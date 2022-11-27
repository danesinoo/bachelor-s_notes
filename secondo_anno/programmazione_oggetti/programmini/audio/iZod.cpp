#include<string>
#include<vector>

using namespace std;
using u32= unsigned int;

class FileAudio {
	private:
		string titolo;
		double dim;
	public:
		virtual FileAudio* clone() const =0;
		virtual bool quality() const =0;
		virtual ~FileAudio() {};
};

class Mp3: public FileAudio {
	private:
		u32 bitrate; // kbit/s
		static u32 qualitybiRate;
	public:
		Mp3* clone() const override {return new Mp3(*this); }
		bool quality() const override {return bitrate >= qualitybiRate;}
};

u32 Mp3::qualitybiRate = 192;

class WAV: public FileAudio {
	private:
		u32 freq; // kHz
		static u32 qualityFreq;
	public:
		WAV* clone() const override {return new WAV(*this); }
		bool quality() const override {return freq >= qualityFreq;}
};

u32 WAV::qualityFreq = 96;

class iZod {
	private:
		class Brano {
			public:
				FileAudio* p;
				Brano(FileAudio* q): p(q->clone()) {}
				Brano(const Brano& b): p(b.p->clone()) {}
				Brano& operator=(const Brano& b) {
					if (this != &b) {
						delete p;
						p = b.p->clone();
					}
					return *this;
				}
				~Brano() {if (p) delete p;} // corretto perchè ~FileAudio è virtuale
		};
		vector<Brano> v;
};

// Chiedere per quanto riguarda il cono se l'implemetazione che potrebbe
// funzionare è:
//
// classe astratta pura solido
// relazione has di cono e di cilindro
