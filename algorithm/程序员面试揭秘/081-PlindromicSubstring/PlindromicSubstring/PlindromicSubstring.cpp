// PlindromicSubstring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Plindromic {
private:
	std::string str;
	size_t strLength;
	/* input string must not be longer than 100 */
	int dp[100][100];
	int pos[2];

private:
	int getCurrentLongestPlindromicLength() {
		return this->pos[1] - this->pos[0] + 1;
	}

	void setCurrentLogestPlinkdromicPos(int i, int j) {
		this->pos[0] = i;
		this->pos[1] = j;
	}

public:
	//ctor
	Plindromic(std::string str) {
		this->str = str;
		this->strLength = str.size();
		for(int i=0; i<100; ++i) {
			for(int j=0; j<100; ++j) {
				this->dp[i][j] = 0;
			}
		}
		this->pos[0] = 0;
		this->pos[1] = 0;
	}

	void initDp() {
		for(int i=0;i<this->strLength;++i) {
			for(int j=i;j<this->strLength;++j) {
				if(j==i) {
					this->dp[i][j]=1;
				}
				else if(j==i+1) {
					if(this->str[i]==this->str[j]) {
						this->dp[i][j]=1;
					}
				}
				
				if(this->dp[i][j]==1 && j-i+1>this->getCurrentLongestPlindromicLength()) {
					this->setCurrentLogestPlinkdromicPos(i, j);
				}
			}
		}
		for(int i=0;i<this->strLength;++i) {
			for(int j=i;j<this->strLength;++j) {
				if(j>i+1) {
					this->dp[i][j] = int(this->dp[i+1][j-1] && (this->str[i]==this->str[j]));
				}

				if(this->dp[i][j]==1 && j-i+1>this->getCurrentLongestPlindromicLength()) {
					this->setCurrentLogestPlinkdromicPos(i, j);
				}
			}
		}
	}

	void printDp() {
		for(int i=0; i<this->strLength; ++i) {
			for(int j=0; j<this->strLength; ++j) {
				std::cout << this->dp[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	std::string getLogestPlindromic() {
		return this->str.substr(this->pos[0], this->getCurrentLongestPlindromicLength());
	}
	
	bool isPlindromic() {
		
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Plindromic p("cartooto");
	p.initDp();
	p.printDp();
	std::cout << p.getLogestPlindromic();
	int response;
	std::cin >> response;
	return 0;
}

