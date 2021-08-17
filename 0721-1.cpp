#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

class Zatsugaku {
protected:
	int level{};
	std::string question;
	std::string choice1;
	std::string choice2;
	std::string choice3;
	int ans{};
	std::string right;
public:
	void setLevel(int newLevel) { level = newLevel; }
	int getLevel() { return level; };
	void setQuestion(const std::string& newQuestion) { question = newQuestion; }
	std::string getQuestion() { return question; }
	void setChoice1(const std::string& newChoice1) { choice1 = newChoice1; }
	std::string getChoice1() { return choice1; }
	void setChoice2(const std::string& newChoice2) { choice2 = newChoice2; }
	std::string getChoice2() { return choice2; }
	void setChoice3(const std::string& newChoice3) { choice3 = newChoice3; }
	std::string getChoice3() { return choice3; }
	void setAns(int newAns) { ans = newAns; }
	int getAns() { return ans; };
	void setRight(const std::string& newRight) { right = newRight; }
	std::string getRight() { return right; }
	bool operator < (const Zatsugaku& another)const {
		return level < another.level;
	}
};
class Sports {
protected:
	int level{};
	std::string question;
	std::string choice1;
	std::string choice2;
	std::string choice3;
	int ans{};
	std::string right;
public:

	void setLevel(int newLevel) { level = newLevel; }
	int getLevel() { return level; };
	void setQuestion(const std::string& newQuestion) { question = newQuestion; }
	std::string getQuestion() { return question; }
	void setChoice1(const std::string& newChoice1) { choice1 = newChoice1; }
	std::string getChoice1() { return choice1; }
	void setChoice2(const std::string& newChoice2) { choice2 = newChoice2; }
	std::string getChoice2() { return choice2; }
	void setChoice3(const std::string& newChoice3) { choice3 = newChoice3; }
	std::string getChoice3() { return choice3; }
	void setAns(int newAns) { ans = newAns; }
	int getAns() { return ans; };
	void setRight(const std::string& newRight) { right = newRight; }
	std::string getRight() { return right; }
	bool operator < (const Sports& another)const {
		return level < another.level;
	}
};

void quiz(int times) {
	std::cout << "ジャンルを選択してください\n" << "1 雑学　2 スポーツ\n";
	int jnl;
	std::cin >> jnl;

	std::ifstream infile;
	int LEVEL;
	std::string QUESTION;
	std::string CHOICE1, CHOICE2, CHOICE3;
	int ANS;
	std::string RIGHT;
	int answer;
	int i = 0;
	if (jnl == 1) {
		std::vector<Zatsugaku>vec1;
		std::ifstream infile("C:/Users/naoto kusuda/Documents/三年前期/プログラミング/testF.text");
		while (infile >> LEVEL >> QUESTION >> CHOICE1 >> CHOICE2 >> CHOICE3 >> ANS >> RIGHT) {
			vec1.emplace_back();
			vec1[i].setLevel(LEVEL);
			vec1[i].setQuestion(QUESTION);
			vec1[i].setChoice1(CHOICE1);
			vec1[i].setChoice2(CHOICE2);
			vec1[i].setChoice3(CHOICE3);
			vec1[i].setAns(ANS);
			vec1[i].setRight(RIGHT);
			i++;
		}

		std::sort(vec1.begin(), vec1.end());
		for (int i = 0; i < times; i++) {
			std::cout << "第[" << i + 1 << "]問　" << vec1[i].getQuestion() << "\n"
				<< vec1[i].getChoice1() << " " << vec1[i].getChoice2() << " " << vec1[i].getChoice3() << "\n"
				<< " >>>";
			std::cin >> answer;
			if (answer == vec1[i].getAns()) {
				std::cout << "正解！\n\n";
			}
			else {
				std::cout << "不正解...\n"
					<< vec1[i].getRight() << "\n";
				std::cout << std::endl;
			}
		}
	}
	else {
		std::vector<Sports>vec2;
		std::ifstream infile("C:/Users/naoto kusuda/Documents/三年前期/プログラミング/testG.text");

		while (infile >> LEVEL >> QUESTION >> CHOICE1 >> CHOICE2 >> CHOICE3 >> ANS >> RIGHT) {
			vec2.emplace_back();
			vec2[i].setLevel(LEVEL);
			vec2[i].setQuestion(QUESTION);
			vec2[i].setChoice1(CHOICE1);
			vec2[i].setChoice2(CHOICE2);
			vec2[i].setChoice3(CHOICE3);
			vec2[i].setAns(ANS);
			vec2[i].setRight(RIGHT);
			i++;
		}

		std::sort(vec2.begin(), vec2.end());
		for (int i = 0; i < times; i++) {
			std::cout << "第[" << i + 1 << "]問　" << vec2[i].getQuestion() << "\n"
				<< vec2[i].getChoice1() << " " << vec2[i].getChoice2() << " " << vec2[i].getChoice3() << "\n"
				<< " >>>";

			std::cin >> answer;
			if (answer == vec2[i].getAns()) {
				std::cout << "正解！\n\n";
			}
			else {
				std::cout << "不正解...\n"
					<< vec2[i].getRight() << "\n";
			}
			std::cout << std::endl;

		}
	}
	infile.close();
}
int main() {
	quiz(3);
}