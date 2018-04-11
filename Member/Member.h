#pragma once

#include <vector>
#include<string> 
using namespace std;


class Member
{
	vector<Member*> users;
	static int counter;
	vector<Member*> followers;
	vector<Member*> following;
	string name;


public:
	Member(string name);
	Member();
	~Member();
	void print(Member p);
	void follow(Member &fol);
	int numFollowers() { return followers.size(); }
	int numFollowing() { return following.size(); }
	void unfollow(Member &un);
	static int count()
	{
		return Member::counter;
	}
};

