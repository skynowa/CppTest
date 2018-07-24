/**
 * FAQ
 *
 * - select(2), kqueue(2), poll(2), epoll(4) и /dev/poll
 * - signals
 *
 * libevent_core:
 * 	- event / event_base
 * 	- bufferevent / evbuffer
 * 		bufferevent_new()
 * 		bufferevent_enable()
 * 		bufferevent_disable()
 * 		bufferevent_read()
 * 		bufferevent_write()
 * 	- evutil
 *
 * libevent_extra:
 * 	- evhttp
 * 	- evdns
 * 	- evrpc
 *
 * libevent_pthreads:
 * 	- pthreads
 *
 * libevent_openssl:
 * 	- OpenSSL
 *
 * https://www.ibm.com/developerworks/ru/library/l-Libevent1/index.html
 * http://www.wangafu.net/~nickm/libevent-book/Ref2_eventbase.html
 * https://github.com/eddieh/libevent-echo-server/blob/master/echo-server.c
 * https://youtu.be/08lbmD-wDfI
 */

#include <iostream>
#include <event2/event.h>

//-------------------------------------------------------------------------------------------------
void
onLog(int severity, const char *msg)
{
	std::cout << "Log: [" << severity << "]: " << msg << std::endl;
}
//-------------------------------------------------------------------------------------------------
void
onFatal(int err)
{
	std::cout << "Error: " << err << std::endl;
}
//-------------------------------------------------------------------------------------------------
// Функция обратного вызова, в которой выполняется прерывание цикла ожидания
void
onEvent(evutil_socket_t fd, short ev_flag, void *arg)
{
#if 0
	struct event_base *base = arg;

	::event_base_loopbreak(base);
	::event_base_loopexit(base);
	::event_base_once(base);
	int event_base_loopcontinue(struct event_base *);
	int event_base_got_exit(struct event_base *);
	int event_base_got_break(struct event_base *);

#else
	const char *data = static_cast<const char *>(arg);

	printf( "Сокет %d - активные события: %s%s%s%s; %s\n", (int)fd,
			(ev_flag & EV_TIMEOUT) ? " таймаут" : "",
			(ev_flag & EV_READ)    ? " чтение"  : "",
			(ev_flag & EV_WRITE)   ? " запись"  : "",
			(ev_flag & EV_SIGNAL)  ? " сигнал"  : "", data );
#endif
}
//-------------------------------------------------------------------------------------------------
// Принудительное завершение цикла обработки событий по истечении заданного интервала времени
void
main_loop_force_exit(event_base *base)
{
	struct timeval seconds;
	seconds.tv_sec  = 3;	// секунды
	seconds.tv_usec = 0;	// микросекунды

	for (int i = 0; i < 5; ++ i) {
		// Планирование выхода из цикла через 3 секунды
		::event_base_loopexit(base, &seconds);
		::event_base_dispatch(base);

		::printf( "%d-й запуск цикла...\n", i + 1);
	}
}
//-------------------------------------------------------------------------------------------------
// Предположим, что вызывающая функция создала два сокета и определила их, как неблокируемые
void
main_loop(event_base *base, evutil_socket_t watch_fd1, evutil_socket_t watch_fd2)
{
   /**
	* Создание нового события, генерируемого при выполнении операции чтения
	* из отслеживаемого сокета (файла). При наступлении этого события
	* вызывается функция обратного вызова call_back, которая выполняет
	* немедленный выход из цикла ожидания данного события и завершение работы программы.
	*/

	if (watch_fd1 == 0 && watch_fd2 == 0) {
		std::cout << "Invalid handle. Exit" << std::endl;
		return;
	}

#if 0
	void *event_self_cbarg(void);
	struct event *event_new(struct event_base *base, evutil_socket_t fd, short what, event_callback_fn cb, void *arg);
	int event_add( struct event *event, const struct timeval *tv );

	// ext
	int event_del(struct event *);
	int event_del_noblock(struct event *ev);
	int event_del_block(struct event *ev);

	void event_active(struct event *ev, int res, short ncalls);
	int event_pending(const struct event *ev, short events, struct timeval *tv);
	struct event *event_base_get_running_event(struct event_base *base);
	int event_initialized(const struct event *ev);
	evutil_socket_t event_get_fd(const struct event *ev);
	struct event_base *event_get_base(const struct event *ev);
	short event_get_events(const struct event *ev);
	event_callback_fn event_get_callback(const struct event *ev);
	void *event_get_callback_arg(const struct event *ev)
	int event_get_priority(const struct event *ev);



	void event_free( struct event *event );
#endif

	event *watch_ev1 = ::event_new(base, watch_fd1, (EV_TIMEOUT|EV_READ|EV_PERSIST), onEvent,
				                 (char *)"тип события: чтение" /* base */);
	event *watch_ev2 = ::event_new(base, watch_fd2, (EV_WRITE|EV_PERSIST), onEvent,
				                 (char *)"тип события: запись" /* base */);

#if 0
	int event_assign(struct event *, struct event_base *, evutil_socket_t, short, event_callback_fn, void *);
#endif
	struct timeval seconds {10, 0};
	::event_add(watch_ev1, &seconds);
	::event_add(watch_ev2, nullptr);

#if 0
	int event_base_loop( struct event_base *base, int flags );
	int event_base_dispatch( struct event_base *base );
#endif
	::event_base_dispatch( base );

	::event_free(watch_ev1);
	::event_free(watch_ev2);
}
//-------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	evutil_socket_t watch_fd1 {};
	evutil_socket_t watch_fd2 {};

#if 0
	int event_reinit(struct event_base *base);
#endif

	event_base *base {};

	// config
	{
	#if 0
		int event_config_avoid_method( struct event_config *cfg, const char *method );
		int event_config_require_features( struct event_config *cfg, enum event_method_feature feature );
		int event_config_set_flag( struct event_config *cfg, enum event_base_config_flag flag );
		int event_config_set_max_dispatch_interval(struct event_config *cfg,
				const struct timeval *max_interval, int max_callbacks, int min_priority);
		struct event_base *event_base_new_with_config( const struct event_config *cfg ); // ::event_base_new()
		void event_config_free( struct event_config *cfg );
	#endif

		event_config *config = ::event_config_new();

		// Запретить использование механизма обработки событий select
		::event_config_avoid_method(config, "select");

		// Запретить блокировки для данного набора событий (предположим, что программа однопоточная)
		::event_config_set_flag(config, EVENT_BASE_FLAG_NOLOCK);

		base = ::event_base_new_with_config(config);

		::event_config_free(config);
		config = nullptr;
	}


	::event_base_priority_init(base, EVENT_MAX_PRIORITIES);
	/// int	event_base_get_npriorities(struct event_base *eb);
	/// int	event_priority_set(struct event *, int);

	/// const struct timeval *event_base_init_common_timeout(struct event_base *base, const struct timeval *duration);

	::event_set_log_callback(onLog);
	::event_set_fatal_callback(onFatal);
	::event_enable_debug_logging(EVENT_DBG_ALL);
	/// void event_base_dump_events(struct event_base *, FILE *);

	// info
	{
		/// int event_base_get_features(const struct event_base *base);

		const char **methods = ::event_get_supported_methods();
		/// ev_uint32_t event_get_version_number(void);

		printf("Starting Libevent %s.  Available methods are:\n", ::event_get_version());

		for (int i = 0; methods[i] != nullptr; ++ i) {
			printf("    %s\n", methods[i]);
		}

		std::cout << "Current method: " << ::event_base_get_method(base) << std::endl;
	}

	/// int event_base_foreach_event(struct event_base *base, event_base_foreach_event_cb fn, void *arg);

	// cache
	/// int event_base_gettimeofday_cached(struct event_base *base, struct timeval *tv);
	/// int event_base_update_cache_time(struct event_base *base);


	::main_loop(base, watch_fd1, watch_fd1);

	::event_base_free(base);
	::libevent_global_shutdown();

	return 0;
}
//-------------------------------------------------------------------------------------------------
