#include <iostream>
using namespace std;

// Base class
class SocialMediaUser {
protected:
    string username;
    int followers;

public:
    SocialMediaUser(string user, int f) {
        username = user;
        followers = f;
    }

    void displayProfile() {
        cout << "Username: " << username << endl;
        cout << "Followers: " << followers << endl;
    }
};

// Derived class 1
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

// Derived class 2
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

// Multilevel inheritance
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

// Hierarchical inheritance
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

int main() {

    // YouTuber object
    YouTuber y1("TechGuru", 50000, "TechGuru Channel");

    cout << "--- YouTuber ---" << endl;
    y1.displayProfile();
    y1.uploadVideo("C++ OOP Tutorial");

    // Podcaster object
    Podcaster p1("PodcastPro", 25000, "Tech Talks");

    cout << "\n--- Podcaster ---" << endl;
    p1.displayProfile();
    p1.publishEpisode("Episode 10 - OOP Concepts");

    // GamingYouTuber object
    GamingYouTuber g1("GamerX", 100000, "GamerX Gaming");

    cout << "\n--- Gaming YouTuber ---" << endl;
    g1.displayProfile();
    g1.uploadVideo("Top 10 Games");
    g1.streamGame("Minecraft");

    // InstagramInfluencer object
    InstagramInfluencer i1("FashionStar", 75000);

    cout << "\n--- Instagram Influencer ---" << endl;
    i1.displayProfile();
    i1.postStory("New Fashion Collection");

    return 0;
}
