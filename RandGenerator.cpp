#include <iostream>
#include <vector>
using namespace std;

class Generators {
private:
    int choice = 0;
    int a = 3;
    int b = 5;
    int c = 11;
    int m = 19997;
    int x = 3;
    int n = 1000;

    vector<double> v_values;
    vector<int> v_histogram;
    vector<int> vector1;
    vector<int> vector2;

public:
    void LinearCongruentialMethod() {
        for (int i = 0; i < n; ++i) {
            x = (x * a + c) % m;
            float u = (float)x / m;
            v_values.push_back(u);
        }
    }

    void QuadraticCongruentialMethod() {
        for (int i = 0; i < n; ++i) {
            x = (a * x * x + b * x + c) % m;
            float u = (float) x / m;
            v_values.push_back(u);
        }
    }

    void FibonacciSequence() {
        int a = 0, b = 1;
        int maxDigits = 10;

        v_values.push_back(a);
        v_values.push_back(b);

        while (v_values.size() < maxDigits) {
            int nextFib = a + b;
            v_values.push_back(nextFib);
            a = b;
            b = nextFib;
        }
    }

    int find_module_inversed(int x, int m){
        int a = 1; // починаємо з одиниці
        while ((a * x) % m != 1){ // перевіряємо чи a * x залишок від ділення m дорівнює 1, якщо не дорівнює то перемо наступне число, а якщо дорівнює то а і є оберненим до x за модулем m
            a++; // переходимо на наступне число
        }
        return a; // за означенням, якщо щось помножити на x = 1 то це шось є обернене до х
    }

    void InverseCongruentialGenerator() {
        for (int i = 0; i < n; ++i) {
            int inver_x = find_module_inversed(x, m);
            x = (a *  inver_x + b) % m;
            v_values.push_back((float) x / m);
        }
    }

    void ThreeSigmaMethod() {
        int n = 100;

        for (int i = 0; i < n; ++i) {
            float sum = 0;
            for (int j = 0; j < 12; j++) {
                x = (x * a + c) % m;
                float u;
                u = (float) x / m;
                sum += u;
            }
            sum -= 6;
            v_values.push_back(sum);
        }
    }

    void showHistogram0To1() {
        cout << "Interval\tFrequency" << endl;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0;

        for (int i = 0; i < n; ++i) {
                if (v_values[i] < 0.1) { c1++; }
            else if (v_values[i] < 0.2) { c2++; }
            else if (v_values[i] < 0.3) { c3++; }
            else if (v_values[i] < 0.4) { c4++; }
            else if (v_values[i] < 0.5) { c5++; }
            else if (v_values[i] < 0.6) { c6++; }
            else if (v_values[i] < 0.7) { c7++; }
            else if (v_values[i] < 0.8) { c8++; }
            else if (v_values[i] < 0.9) { c9++; }
            else c10++;
        }

        cout << "[0 to 0.1]  \t" << (float) c1/n << endl;
        cout << "[0.1 to 0.2]\t" << (float) c2/n << endl;
        cout << "[0.2 to 0.3]\t" << (float) c3/n << endl;
        cout << "[0.3 to 0.4]\t" << (float) c4/n << endl;
        cout << "[0.4 to 0.5]\t" << (float) c5/n << endl;
        cout << "[0.5 to 0.6]\t" << (float) c6/n << endl;
        cout << "[0.6 to 0.7]\t" << (float) c7/n << endl;
        cout << "[0.7 to 0.8]\t" << (float) c8/n << endl;
        cout << "[0.8 to 0.9]\t" << (float) c9/n << endl;
        cout << "[0.9 to 1]  \t" << (float) c10/n << endl;
    }

    void showHistogramNeg3To3() {
        cout << "Interval\tFrequency" << endl;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0;

        for (const float& value : v_values) {
                if (value < -2.4)  { c1++; }
            else if (value < 1.8)  { c2++; }
            else if (value < -1.2) { c3++; }
            else if (value < -0.6) { c4++; }
            else if (value < 0)    { c5++; }
            else if (value < 0.6)  { c6++; }
            else if (value < 1.2)  { c7++; }
            else if (value < 1.8)  { c8++; }
            else if (value < 2.4)  { c9++; }
            else c10++;
        }

        cout << "[-3 to -2.4]\t" << (float) c1/n << endl;
        cout << "[-2.4 to -1.8]\t" << (float) c2/n << endl;
        cout << "[-1.8 to -1.2]\t" << (float) c3/n << endl;
        cout << "[-1.2 to -0.6]\t" << (float) c4/n << endl;
        cout << "[-0.6 to 0]\t    "<< (float) c5/n << endl;
        cout << "[0 to 0.6]\t    " << (float) c6/n << endl;
        cout << "[0.6 to 1.2]\t" << (float) c7/n << endl;
        cout << "[1.2 to 1.8]\t" << (float) c8/n << endl;
        cout << "[1.8 to 2.4]\t"   << (float) c9/n << endl;
        cout << "[2.4 to 3]\t    "<< (float) c10/n << endl;
    }

    void showMenu() {
        do {
            cout << "[0] Quit" << endl;
            cout << "[1] Linear congruential method" << endl;
            cout << "[2] Quadratic congruential method" << endl;
            cout << "[3] Digit of Fibonacci" << endl;
            cout << "[4] Inverse congruential generator" << endl;
            cout << "[5] Method of merge" << endl;
            cout << "[6] 3-x sigma" << endl;

            cout << "[7] Polar coordinate method" << endl;
            cout << "[8] The ratio method" << endl;
            cout << "[9] The logarithm method for generating a representative distribution" << endl;
            cout << "[10] Ahren's method for generating a gamma distribution of order a > 1" << endl;
            cout << "Enter choice (0-10): ";
            cin >> choice;
            cout << endl;

            switch (choice) {
                case 0: return;
                case 1: // well
                    LinearCongruentialMethod();
                    showHistogram0To1();
                    break;

                case 2: // well
                    QuadraticCongruentialMethod();
                    showHistogram0To1();
                    break;

                case 3: // well
                    FibonacciSequence();
                    showHistogram0To1();
                    break;

                case 4:
                    InverseCongruentialGenerator();
                    showHistogram0To1();
                    break;

                case 5:


                    break;

                case 6:
                    ThreeSigmaMethod();
                    showHistogramNeg3To3();
                    // 6, 7,8, neg3 to 3
                    break;

                default:
                    cout << "Invalid choice. Select from 0 to 10!" << endl;
                    break;
            }

            v_values.clear();
            v_histogram.clear();
            choice = 0;
            cout << endl;
        } while (true);
    }
};

int main() {
    Generators generators;
    generators.showMenu();
    return 0;
}