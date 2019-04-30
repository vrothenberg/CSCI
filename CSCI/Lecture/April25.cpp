#include <iostream>

using namespace std;

class Scores {
public:
  Scores(int size);

  void FillUp();

  void Output();

private:
  int size_;
  int *scores_;
};

int main() {
  /*

  int size_row; size_col, sum;

  int **quizzes;

  cout << "How many students? ";
  cin >> size_row;

  cout >> "How many quizzes? ";
  cin >> size_col;

  quizzes = new int*[size_row];
  for(int i = 0; i < size_row; i++) {
    quizzes[i] = new int[size_col];
  }

  for (int i = 0; i < size_row; i++) {
    for (int j = 0; j < size_col; j++) {
      cout << "Grades for student" << i + 1 << ", Quiz" << j + 1 < ": ";
      cin >> quizzes[i][j];
    }
  }
  //UNFINISHED!
  for (int i = 0; i < size_row; i++) {
    cout << "Grades for student: " << i+1 << endl;
    sum = 0;
    for (int j = 0; j < size_col; j++) {
      sum += quizzes[i][j];
      cout << "Grades for student" << i + 1 << ", Quiz" << j + 1 < ": ";
      cout << quizzes[i][j];
    }
  }

  */

  Scores *obj = new Scores(5);

  obj->FillUp();
  obj->Output();

  obj = new Scores(8);
  obj->FillUp();
  obj->Output();

  return 0;
}

Scores::Scores(int size) {
  if (size < 1 ) {
    size = 10;
  }
  size_ = size;
  scores_ = new int[size_];
}

void Scores::FillUp() {
  for (int i = 0; i < size_; i++) {
    cout << "Enter score #" << i+1  << ": ";
    cin >> scores_[i];
  }

}

void Scores::Output() {

  for (int i = 0; i < size_-1; i++) {
    cout << scores_[i] << ", ";
  }
  cout  << scores_[size_ -1] << endl;

}
