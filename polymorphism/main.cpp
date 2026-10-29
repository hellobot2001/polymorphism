#include <iostream>
#include <string>
#include <vector>

using namespace std;

class instrument {
public:
	string name;
	string sound;
	instrument(string n, string v)
	{
		name = n;
		sound = v;
	}
	virtual void play() = 0;
};

class trumpet : public instrument {
public:
	trumpet() : instrument("trumpet", "doot doot doot") {}
	void play() { cout << sound << endl; }
};

class violin : public instrument {
public:
	violin() : instrument("violin", "vwa vwa vwa vwa vwa") {}
	void play() { cout << sound << endl; }
};

class piano : public instrument {
public:
	piano() : instrument("piano", "dee dee") {}
	void play() { cout << sound << endl; }
};

class singer : public instrument {
public:
	singer() : instrument("singer", "blah blah blah blah blah") {}
	void play() { cout << sound << endl; }
};

class trombone : public instrument {
public:
	trombone() : instrument("trombone", "Dwooooo~") {}
	void play() { cout << sound << endl; }
};

class orchestra {
private:
	vector<instrument*> o;
public:
	orchestra() {}

	void addInstrument(instrument* i)
	{
		o.push_back(i);
	}

	void play()
	{
		for (instrument* i : o)
		{
			i->play();
		}
	}
};

int main()
{
	trumpet t = trumpet();
	violin v = violin();
	piano p = piano();
	singer s = singer();
	trombone t2 = trombone();
	orchestra o = orchestra();
	o.addInstrument(&t); o.addInstrument(&v); o.addInstrument(&p); o.addInstrument(&t2); o.addInstrument(&s);
	o.play();
}