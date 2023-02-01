#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> fromTime;
vector<string> endTime;
map<string, int> numCall, totalTime;
int totalCall = 0;
int incorrectNum = 0;

bool checkPhoneNum(string num) {
  if (num.length() != 10)
    return false;
  for (int i = 0; i < num.length(); i++) {
    if (num[i] < 48 || num[i] > 57) {
      return false;
    }
  }
  return true;
}

int countTime(string sTime, string eTime) {
  int startTime = 3600 * ((sTime[0] - '0') * 10 + sTime[1] - '0') +
                  60 * ((sTime[3] - '0') * 10 + sTime[4] - '0') +
                  (sTime[6] - '0') * 10 + sTime[7] - '0';
  int endTime = 3600 * ((eTime[0] - '0') * 10 + eTime[1] - '0') +
                60 * ((eTime[3] - '0') * 10 + (eTime[4] - '0')) +
                (eTime[6] - '0') * 10 + eTime[7] - '0';
  return endTime - startTime;
}

int main(int argc, char *argv[]) {
  string x;

  do {
    cin >> x;
    if (x == "#")
      continue;
    string fromNum, toNum, date, fTime, eTime;
    cin >> fromNum >> toNum >> date >> fTime >> eTime;
    if (!checkPhoneNum(fromNum) || !checkPhoneNum(toNum))
      ++incorrectNum;
    numCall[fromNum]++;
    totalCall++;
    totalTime[fromNum] += countTime(fTime, eTime);
  } while (x != "#");

  do {
    cin >> x;
    if (x == "#")
      continue;
    if (x == "?check_phone_number") {
      if (incorrectNum > 0)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else if (x == "?number_calls_from") {
      string phone;
      cin >> phone;
      cout << numCall[phone] << endl;
    } else if (x == "?count_time_calls_from") {
      string phone;
      cin >> phone;
      cout << totalTime[phone] << endl;
    } else if (x == "?number_total_calls") {
      cout << totalCall << endl;
    }
  } while (x != "#");

  return 0;
}
