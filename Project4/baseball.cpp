#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	GuessResult guess(const string& guessNumber) {
		GuessResult result = { false, 0,0 };
		assertIllegalArgument(guessNumber);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (guessNumber[i] == question[j]) {
					if (i == j) result.strikes++;
					else result.balls++;
				}
			}
		}

		if (result.strikes == 3)
			result.solved = true;

		return result;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	string question;
};