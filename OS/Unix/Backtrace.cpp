/**
 * \file  Backtrace.cpp
 * \brief Bactrace
 *
 * c++ -g -O0 ./Backtrace.cpp -rdynamic -ldl -fpermissive -o ./Backtrace
 *
 * \see https://stackoverflow.com/questions/55450932/how-ro-resolve-cpp-symbols-from-backtrace-symbols-in-the-offset-during-runtime
 */


#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <dlfcn.h>
#include <execinfo.h>

void  print_stack();
void* parse_symbol_offset(char *frame);
char* addr2line_format(void *addr, char *symbol, char *buffer, int nn_buffer);

const char* program = nullptr;
//-------------------------------------------------------------------------------------------------
void
print_stack()
{
    void *addresses[64] {};

    const int nn_addresses = ::backtrace(addresses, sizeof(addresses) / sizeof(void *));

    printf("%s addresses:\n", ::program);

    for (int i = 0; i < nn_addresses; i++) {
        printf("%p\n", addresses[i]);
    }

    char **symbols = ::backtrace_symbols(addresses, nn_addresses);

    printf("\nsymbols:\n");

    for (int i = 0; i < nn_addresses; ++ i) {
        printf("%s\n", symbols[i]);
    }

    char buffer[128] {};

    printf("\nframes:\n");

    for (int i = 0; i < nn_addresses; ++ i) {
        void *frame = ::parse_symbol_offset(symbols[i]);
        char *fmt   = ::addr2line_format(frame, symbols[i], buffer, sizeof(buffer));

        int parsed = (fmt == buffer);
        printf("%p %d %s\n", frame, parsed, fmt);
    }

    free(symbols);
}
//-------------------------------------------------------------------------------------------------
void *
parse_symbol_offset(
	char *frame
)
{
    char        *p_symbol {};
    std::size_t  nn_symbol {};
    char        *p_offset {};
    std::size_t  nn_offset {};

    // Read symbol and offset, for example:
    //      /tools/backtrace(foo+0x1820) [0x555555555820]
    for (char *p = frame; *p; ++ p) {
        if (*p == '(') {
            p_symbol = p + 1;
        }
        else if (*p == '+') {
            if (p_symbol) {
            	nn_symbol = p - p_symbol;
            }

            p_offset = p + 1;
        }
        else if (*p == ')') {
            if (p_offset) {
            	nn_offset = p - p_offset;
            }
        }
    }

    if (!nn_symbol &&
    	!nn_offset)
    {
        return nullptr;
    }

    // Convert offset(0x1820) to pointer, such as 0x1820.
    char tmp[128] {};
    if (!nn_offset ||
    	nn_offset >= sizeof(tmp))
    {
        return nullptr;
    }

    int r0 = EOF;
    void* offset {};
    tmp[nn_offset] = 0;
    if ((r0 = sscanf(strncpy(tmp, p_offset, nn_offset), "%p", &offset)) == EOF) {
        return nullptr;
    }

    // Covert symbol(foo) to offset, such as 0x2fba.
    if (!nn_symbol ||
    	nn_symbol >= sizeof(tmp))
    {
        return offset;
    }

    void *object_file {};
    if ((object_file = ::dlopen(nullptr, RTLD_LAZY)) == nullptr) {
        return offset;
    }

    void *address {};
    tmp[nn_symbol] = 0;
    if ((address = ::dlsym(object_file, strncpy(tmp, p_symbol, nn_symbol))) == nullptr) {
        ::dlclose(object_file);
        return offset;
    }

    Dl_info symbol_info {};
    if ((r0 = ::dladdr(address, &symbol_info)) == 0) {
        ::dlclose(object_file);
        return offset;
    }

    ::dlclose(object_file);

    return (std::size_t)symbol_info.dli_saddr - (std::size_t)symbol_info.dli_fbase + (std::size_t)offset;
}
//-------------------------------------------------------------------------------------------------
char *
addr2line_format(
	void *addr,
	char *symbol,
	char *buffer,
	int   nn_buffer
)
{
    char cmd[512] {};
    int r0 = snprintf(cmd, sizeof(cmd), "addr2line -C -p -s -f -a -e %s %p", ::program, addr);
    if (r0 < 0 || r0 >= static_cast<int>(sizeof(cmd))) {
    	return symbol;
    }

    FILE* fp = popen(cmd, "r");
    if (!fp) {
    	return symbol;
    }

    char* p = fgets(buffer, nn_buffer, fp);
    pclose(fp);

    if (p == nullptr) {
    	return symbol;
    }

    if ((r0 = strlen(p)) == 0) {
    	return symbol;
    }

    // Trait the last newline if exists.
    if (p[r0 - 1] == '\n') {
    	p[r0 - 1] = '\0';
    }

    // Find symbol not match by addr2line, like
    //      0x0000000000021c87: ?? ??:0
    //      0x0000000000002ffa: _start at ??:?
    for (p = buffer; p < buffer + r0 - 1; ++ p) {
        if (p[0] == '?' &&
        	p[1] == '?')
        {
        	return symbol;
        }
    }

    return buffer;
}
//-------------------------------------------------------------------------------------------------
int
main(int, char** argv)
{
    ::program = argv[0];
    print_stack();

    return EXIT_SUCCESS;
}
//-------------------------------------------------------------------------------------------------
