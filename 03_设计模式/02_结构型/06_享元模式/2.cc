#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class User {
public:
  string name;
  User(string name) : name(name) {}
};

class WebSite {
public:
  void show(User *user) { cout << user->name << endl; };
};

class ConcreateWebSite : public WebSite {
private:
  string type;

public:
  ConcreateWebSite(string type) : type(type) {}
};

class WebSiteFactory {
public:
  unordered_map<string, WebSite *> map;
  WebSite *getWebsite(string type) {
    if (map.find(type) != map.end()) {
      map[type] = new ConcreateWebSite(type);
    }
    return map[type];
  }
  int getCount() { return map.size(); }
};

int main() {
  auto factory = new WebSiteFactory();
  auto web = factory->getWebsite("web");
  web->show(new User("aha"));

  auto news = factory->getWebsite("news");
  news->show(new User("xl"));

  auto news1 = factory->getWebsite("news");
  news->show(new User("xl2"));

  auto news2 = factory->getWebsite("news");
  news->show(new User("xl3"));

  cout << factory->getCount() << endl;

  return 0;
}