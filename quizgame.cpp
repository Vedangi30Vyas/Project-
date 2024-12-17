#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a question
struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer;

    Question(string text, vector<string> opts, char answer)
        : questionText(text), options(opts), correctAnswer(answer) {}
};

// Function to display a single question
void displayQuestion(const Question& question, int questionNumber) {
    cout << "Question " << questionNumber << ": " << question.questionText << endl;
    for (int i = 0; i < question.options.size(); i++) {
        cout << char('A' + i) << ". " << question.options[i] << endl;
    }
    cout << "Your Answer (A, B, C, D): ";
}

// Main Quiz Function
void startQuiz() {
    vector<Question> questions = {
        Question("What is the capital of France?",
                 {"Paris", "London", "Berlin", "Madrid"}, 'A'),
        Question("Which planet is known as the Red Planet?",
                 {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'),
        Question("Who wrote 'Hamlet'?",
                 {"Charles Dickens", "J.K. Rowling", "William Shakespeare", "Mark Twain"}, 'C'),
        Question("Which programming language is known for its simplicity?",
                 {"C++", "Python", "Java", "Assembly"}, 'B'),
        Question("What is 2 + 2?",
                 {"3", "4", "5", "6"}, 'B')
    };

    int score = 0;

    cout << "Welcome to the Quiz Game!" << endl;
    cout << "Answer the following questions:" << endl;

    for (int i = 0; i < questions.size(); i++) {
        displayQuestion(questions[i], i + 1);
        char userAnswer;
        cin >> userAnswer;
        userAnswer = toupper(userAnswer); // Normalize input to uppercase

        if (userAnswer == questions[i].correctAnswer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer was " << questions[i].correctAnswer << "." << endl;
        }
        cout << endl;
    }

    cout << "Quiz Over! Your Score: " << score << "/" << questions.size() << endl;

    if (score == questions.size()) {
        cout << "Excellent! You're a genius!" << endl;
    } else if (score >= questions.size() / 2) {
        cout << "Good job! You did well!" << endl;
    } else {
        cout << "Better luck next time!" << endl;
    }
}

int main() {
    startQuiz();
    return 0;
}

