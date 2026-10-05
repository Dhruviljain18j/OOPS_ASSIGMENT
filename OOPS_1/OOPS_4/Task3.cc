class Podcaster : public SocialMediaUser {
private:
    string podcastName;

public:
    Podcaster(string user, int f, string podcast)
        : SocialMediaUser(user, f) {
        podcastName = podcast;
    }

    void publishEpisode(string episodeTitle) {
        cout << "Episode " << episodeTitle
             << " published on " << podcastName << endl;
    }
};
