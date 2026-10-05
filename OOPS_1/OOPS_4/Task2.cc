class YouTuber : public SocialMediaUser {
protected:
    string channelName;

public:
    YouTuber(string user, int f, string channel)
        : SocialMediaUser(user, f) {
        channelName = channel;
    }

    void uploadVideo(string title) {
        cout << "Video " << title
             << " uploaded to " << channelName << endl;
    }
};
