#include <iostream>
#include <list>

using namespace std;

class YoutubeChannels {
private:
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideosTitle;
protected:
	string Name;
	int ContentQuality;
public:
	YoutubeChannels(string name, string ownername) {
		Name = name;              // default variables
		OwnerName = ownername;
		ContentQuality = 0; 
	}
	void getInfo() {
		cout << "Name              :" << Name << endl;
		cout << "OwnerName         :" << OwnerName << endl;
		cout << "SubscribersCount  :" << SubscribersCount << endl;
		cout << "Videos            :" << endl;
		for (string videos_title : PublishedVideosTitle) {
			cout << videos_title << endl;
		}
		}
	void Subscriber(int value ){
		SubscribersCount = value;
	}
	void Published(string videos_title) {
		PublishedVideosTitle.push_back(videos_title);
	}
	void CheckAnalytics() {
		if (ContentQuality < 5) {
			cout << Name << " has bad quality content." << endl;
		}
		else {
			cout << Name << " has great content." << endl;
		}
	}
};

class SliveraiYoutubeChannels :public YoutubeChannels {
public:
	SliveraiYoutubeChannels(string name, string ownername) : YoutubeChannels(name, ownername) {
	}
	void Paractise() {
		if (ContentQuality < 1) {
			cout << Name << " is paracticing cooking , learning new repices , experimenting with spiceses... " << endl;
		}
		ContentQuality++;
	}
};

class SingingYoutubeChannels : public YoutubeChannels {
public:
	SingingYoutubeChannels(string name, string ownername) : YoutubeChannels( name, ownername) {

	}
	void Paractise() {
		if (ContentQuality < 1) {
			cout << Name << "  is taking singing classes , learning new songs , learning how to dance ..." << endl;
		}
		ContentQuality++;
	}
};

int main()
{
	int paractises,count;

	cout << "Enter Number : " << endl;
	cin >> paractises;
	cout << "Enter the SubscribersCount  : " << endl;
	cin >> count;

	system("cls");

	YoutubeChannels ytchannel("Emre's Kitchen ", "Emre");
	SliveraiYoutubeChannels slchannels("Sliverai", "Yunus Emre TAHA");
	SingingYoutubeChannels sgchannels("Singing John's", "John");

	ytchannel.Published("C++ for beginners ");
	ytchannel.Published("HTML & CSS for beginners ");
	ytchannel.Published("C++ OOP ");

	ytchannel.Subscriber(count);
	cout << "THIS YOUTUBE CHANNELS :" << endl;

	ytchannel.getInfo();

	for (int i = 0; i < paractises; i++) {
		slchannels.Paractise();
	}

	YoutubeChannels* yt1 = &slchannels;
	YoutubeChannels* yt2 = &sgchannels;

	yt1->CheckAnalytics();
	yt2->CheckAnalytics();

}
