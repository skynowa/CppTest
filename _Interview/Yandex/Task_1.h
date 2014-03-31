// ѕерепишите код, устранив имеющиес€ в нЄм проблемы, но не измен€€ функцию main
// http://forum.vingrad.ru/forum/topic-365389.html

class Foo {
 public:
  Foo(int j) { i = new int[j]; }
  ~Foo() { delete i; }

 private:
  int* i;
};

class Bar: Foo {
 public:
  Bar(int j) { i = new char[j]; }
  ~Bar() { delete i; }

 private:
  char* i;
};

void main() {
  Foo* f = new Foo(100);
  Foo* b = new Bar(200);
  *f = *b;
  delete f;
  delete b;
}


// ответ

class Foo 
{
public:

	Foo() : size(0)
	{
		Foo::i = 0;
	};	

	Foo(int j) : size(j)
	{ 
		Foo::i = new int[j]; 		
	}

	virtual ~Foo() 
	{
		Clear();
	};
	
	Foo& operator=( const Foo &rhs )
	{
		Clear();

		Foo::i = new int[rhs.size];
		size = rhs.size;

		return *this;
	}

private:

	void Clear()
	{
		if(0 != Foo::i)
		{
			delete [] Foo::i; 
			Foo::i = 0;
		}
	}

protected:

	int* i;
	unsigned int size;
};

class Bar: public Foo 
{
public:	

	Bar(int j) : Foo(j)
	{ 		
		Bar::i = new char[j]; 		
	};

	~Bar()
	{
		if(0 != Bar::i)
		{
			delete [] Bar::i; 
			Bar::i = 0;
		}
	}

protected:

	char* i;
};

void main() 
{
	Foo* f = new Foo(100);
	Foo* b = new Bar(200);

	*f = *b;

	delete f;
	delete b;
}
