class GamingYouTuber : public YouTuber {
public:
    GamingYouTuber(string user, int f, string channel)
        : YouTuber(user, f, channel) {
    }

    void streamGame(string gameName) {
        cout << username << " is now streaming "
             << gameName << " on " << channelName << endl;
    }
};
