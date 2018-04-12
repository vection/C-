#include "Member.h"

#include <iostream>
using namespace std;


int Member::counter = 0;
void Member::follow(Member &fol)
{

	for (int i = 0; i < following.size(); i++)
	{
		if (following[i] == &fol)return;
	}
	following.push_back(&fol); 
	fol.followers.push_back(this);
}

void Member::print(Member p) {
	Member* temp = &p;
	cout << "Followers: " << temp->followers.size() << " Following: " << temp->following.size() << endl;
}

void Member::unfollow(Member &temp) {
		for (int i = 0; i < this->following.size(); i++) {
			if (this->following[i] == &temp) {
				following.erase(following.begin() + i);
				for (int j = 0; j < temp.followers.size(); j++) {
					if (temp.followers[j] == this) { temp.followers.erase(temp.followers.begin() + j); }
				}
			}
	    }
}

Member::Member() {
	this->name = "null";
	users.push_back(this);
	counter++;
}

Member::Member(std::string name)
{
	this->name = name;
	users.push_back(this);
	counter++;
}


Member::~Member()
{
	for (int i = 0; i < this->following.size(); i++) {
		Member* temp = this->following[i];
		for (int j = 0; j < temp->followers.size(); j++) {
			if (temp->followers[i] == this) { temp->followers.erase(temp->followers.begin() + j); }
		}
	}
	for (int i = 0; i < this->followers.size(); i++) {
		Member* temp = this->followers[i];
		for (int j = 0; j < temp->following.size(); j++) {
			if (temp->following[i] == this) { temp->following.erase(temp->following.begin() + j); }
		}
	}
	for (int i = 0; i < users.size(); i++) {
		if (this == users[i]) { users.erase(users.begin() + i); }
	}
	counter--;
}
