#include <iostream>
#include <string>

using namespace std;

class IPlay {
public:
    virtual ~IPlay() = default;
    virtual void play(const string&) = 0;
};

class IPause {
public:
    virtual ~IPause() = default;
    virtual void pause() = 0;
};

class IIsPlaying {
public:
    virtual ~IIsPlaying() = default;
    virtual bool isPlaying() const = 0;
};

class IDownload{
    public:
        virtual ~IDownload()=default;
        virtual void download(const string&url)=0;
};

class IisLive{
    public:
        virtual ~IisLive()=default;
        virtual bool isLive() const =0;
};

class IStreamLive{
    public: 
        virtual ~IStreamLive()=default;
        virtual void streamLive(const string&)=0;
};

class LiveAction: public IisLive, public IStreamLive{
    private:
        bool liveStarted{false};
    public: 
        void streamLive(const string& url) override{
            (void)url;
            liveStarted=true;
        }
        bool isLive() const override{
            return liveStarted;
        }
};

class IRecord{
    public:
        virtual ~IRecord()=default;
        virtual void record(const string &dest)=0;
};

class Record:public IRecord{
    public:
        void record(const string& dest) override{
            (void)dest;
        }
};

class AudioPlayPause : public IPlay, public IPause, public IIsPlaying {
    bool playing{false};
public:
    void play(const string& source) override { (void)source; playing = true; }
    void pause() override { playing = false; }
    bool isPlaying() const override { return playing; }
};

class Download:public IDownload{
    public:
        void download(const string&url) override{
            cout<<"Downloading from url : "<<url<<endl;
        }
};

class AudioPlayer {
    IPlay& play;
    IPause& pause;
    IIsPlaying& state;
    IDownload& down;
public:
    AudioPlayer(IPlay& p, IPause& u, IIsPlaying& s,IDownload &d)
        : play(p), pause(u), state(s), down(d){}

    void start(const string& src) { play.play(src); }
    void stop() { pause.pause(); }
    bool isPlaying() const { return state.isPlaying(); }
    void download(const string &url) const {
        down.download(url);
    }
};

class CameraStreamPlayer{
    IPlay& Play;
    IPause& Pause;
    IRecord& Record;
    IStreamLive& StreamLive;
    IIsPlaying& state;
    IisLive& IsLive;
    public:
        CameraStreamPlayer(IPlay& p, IPause& u,IIsPlaying &ip,IRecord& r,IStreamLive &s,IisLive &l): Play(p),Pause(u),Record(r),StreamLive(s),state(ip),IsLive(l) {}
        void play(const string& src){
            Play.play(src);
        } 
        void pause(){
            Pause.pause();
        }
        void record(const string& dest){
            Record.record(dest);
        }
        void streamLive(const string &url){
            StreamLive.streamLive(url);
        }
        bool isPlaying() const{
            return state.isPlaying();
        }
        bool isLive() const{
            return IsLive.isLive();
        }
};

int main() {
    AudioPlayPause impl;  
    Download down;
    AudioPlayer ap(impl, impl, impl,down);

    ap.start("song.mp3");
    cout << boolalpha << ap.isPlaying() << "\n";
    ap.stop();

    LiveAction lvaction;
    AudioPlayPause impl1;
    Record record;
    LiveAction liveaction;
    CameraStreamPlayer(impl1,impl1,impl1,record,liveaction,liveaction);
    return 0;
}
