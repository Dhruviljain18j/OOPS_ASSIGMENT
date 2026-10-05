class InstagramInfluencer : public SocialMediaUser {
public:
    InstagramInfluencer(string user, int f)
        : SocialMediaUser(user, f) {
    }

    void postStory(string storyTitle) {
        cout << username
             << " posted a new story: "
             << storyTitle << endl;
    }
};
