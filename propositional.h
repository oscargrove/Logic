// History
// Created: Oscar Grove 22/05/2021
//
// Modified:

#include <iostream>

using namespace std;

class object
{
	char type ();
};

class set : public object
{
	object* x;
	set* xs;

public:
	set (object* O)
	{
		x = O;
	}

	bool contains (object* O)
	{
		if (*x == *O)
			return true;

		if (xs == NULL)
			return false;

		return xs -> contains (O);
	}

	object* head ()
	{
		return x;
	}

	set* tail ()
	{
		return xs;
	}

	void add (object* O)
	{
		if (not (this -> contains (O)))
		{
			if (x == NULL)
				x = O;

			else if (xs == NULL)
				xs = new set (O);

			else
				xs -> add (O);
		}
	}

	void remove (object* O)
	{
		if (this -> contains (O))
		{
			if (*x == *O)
			{
				x = xs -> head ();

				xs = xs -> tail ();
			}

			else
				xs = xs -> remove (O);
		}
	}

	char type ()
	{
		return 'S';
	}

	void print ()
	{
		if (x == NULL)
			return;

		x -> print ();

		if (xs != NULL)
			cout << ", ";

		xs -> print ();
	}
};

class operator : public object
{
	string label;
	int arity;

public:
	operator (string s, int n)
	{
		label = s;
		arity = n;
	}

	int size ()
	{
		return arity;
	}

	void print ()
	{
		cout << label;
	}

	char type ()
	{
		return 'O';
	}
}

class formula : public object
{
	operator* op;

	set* F;

public:
	formula (operator* o, set* S)
	{
		op = o;

		F = S;
	}

	void print ()
	{
		if (op -> size () == 1)
		{
			op -> print ();

			F -> print ();
		}

		else if (op -> size () == 2)
		{
			cout << "(";

			F -> head () -> print ();

			op -> print;

			F -> tail () -> print ();
		}

		else
		{
			op -> print ();

			cout << "(";

			F -> print ();

			cout << ")";
		}
	}

	char type ()
	{
		return 'F';
	}
};

class variable : public formula
{
	char symbol;

public:
	variable (char c) : formula ()
	{
		symbol = c;
	}

	char label ()
	{
		return symbol;
	}

	void print ()
	{
		cout << symbol;
	}

	char type ()
	{
		return 'V';
	}

	bool operator == (variable x)
	{
		return x.label () == symbol;
	}
}

class rule : public object
{
	set* premises;
	formula* conclusion;
}

class logic : public object
{
	set* variables;
	set* operators;
	set* rules;
	set* axioms;
};