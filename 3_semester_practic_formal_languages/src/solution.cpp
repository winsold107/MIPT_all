#include <iostream>
#include <vector>
#include <limits>
#define max3(x,y,z) max(max((x),(y)), (z))

using namespace std;

int NUM = (-1) * numeric_limits <int>::max();

struct Node {
    int wholeReg;
    int ansVal;
    int suffVal;
    int prefVal;
};

int stackFill(string regExp, char x, int k) {
    vector <Node> stackOfNFA;
    for (auto const &sym: regExp) {
        if (sym == x) {
            Node n;
            n.ansVal = 1;
            n.suffVal = 1;
            n.prefVal = 1;
            n.wholeReg = 1;
            stackOfNFA.push_back(n);
        }

        else if (sym != x && sym != '.' && sym != '*' && sym != '+') {
            Node n;
            n.ansVal = 0;
            n.suffVal = 0;
            n.wholeReg = NUM;
            n.prefVal = 0;
            stackOfNFA.push_back(n);
        }

        else if (sym == '.') {
            if (stackOfNFA.empty()) {
                return -1;
            }
            Node second = stackOfNFA.back();
            stackOfNFA.pop_back();
            if (stackOfNFA.empty()) {
                return -1;
            }
            Node first = stackOfNFA.back();
            stackOfNFA.pop_back();
            Node n;

            n.prefVal = max(first.prefVal, second.prefVal + first.wholeReg);
            n.suffVal = max(second.suffVal, first.suffVal + second.wholeReg);
            n.ansVal = max3(first.ansVal, second.ansVal, first.suffVal + second.prefVal);
            if (first.wholeReg < 0 || second.wholeReg < 0) {
                n.wholeReg = NUM;
            }
            else {
                n.wholeReg = first.wholeReg + second.wholeReg;
            }
            stackOfNFA.push_back(n);
        }

        else if (sym == '+') {
            if (stackOfNFA.empty()) {
                return -1;
            }
            Node second = stackOfNFA.back();
            stackOfNFA.pop_back();
            if (stackOfNFA.empty()) {
                return -1;
            }
            Node first = stackOfNFA.back();
            stackOfNFA.pop_back();
            Node n;
            n.prefVal = max(first.prefVal, second.prefVal);
            n.suffVal = max(first.suffVal, second.suffVal);
            n.wholeReg = max(first.wholeReg, second.wholeReg);
            n.ansVal = max(first.ansVal, second.ansVal);
            stackOfNFA.push_back(n);
        }

        else if (sym == '*') {
            if (stackOfNFA.empty()) {
                return -1;
            }
            Node last = stackOfNFA.back();
            stackOfNFA.pop_back();
            Node n;

            if (last.wholeReg == 0) {
                n.wholeReg = 0;
            }

            else if (last.wholeReg > 0) {
                n.wholeReg = (-1) * NUM;
            }

            else {
                n.wholeReg = max(0, last.wholeReg);
            }

            n.suffVal = max(n.wholeReg, last.suffVal);
            n.prefVal = max(n.wholeReg, last.prefVal);
            n.ansVal = max3(n.wholeReg, last.suffVal + last.prefVal, last.ansVal);
            stackOfNFA.push_back(n);
        }
    }

    if (stackOfNFA.size() != 1) {
        return -1;
    }

    else {
        if (stackOfNFA.back().ansVal >= k) {
            return 0;
        }

        else {
            return 1;
        }
    }
}

int regExpParser() {
    string regExp;
    char x;
    int k;
    cin >> regExp >> x >> k;

    int potential_answer = stackFill(regExp, x, k);

    if (potential_answer == -1) {
        cout << "ERROR" << endl;
    }

    else {
        if (potential_answer == 0) {
            cout <<  "YES";
        }

        else {
            cout << "NO";
        }
    }
    return 0;
}
//
//ВАРИАНТ 4 (ДАНО РЕГУЛЯРНОЕ ВЫРАЖЕНИЕ, БУКВА Х, НЕКОТОРОЕ ЧИСЛО К. ВЫВЕСТИ "YES", ЕСЛИ ЯЗЫКУ, ЗАДАВАЕМОМУ ВВЕДЕННЫМ РЕГУЛЯРНЫМ ВЫРАЖЕНИЕМ, ПРИНАДЛЕЖИТ СЛОВО, У КОТОРОГО СУЩЕСТВУЕТ ПОДСЛОВО ХХ...Х (К РАЗ), ИНАЧЕ ВЫВЕСТИ "NO")
//
//АЛГОРИТМ
//
//        Алгоритм заключается в построении стека (в котором элементы это кортежи из 4 чисел: результат для суффикса, для префикса, некий ответ, может ли регулярка являться вся последовательностью хх...х (к раз)) в процессе рассмотрения регулярного выражения. То есть принимая поочередно символы регулярного выражения мы работаем с элементами стека так, что в конце обработки получим ответ. Будем искать максимальное такое к, что подслово хх...х (к раз) существует.
//
//Все элементы регулярного выражения можно разделить на несколько случаев:
//1 случай: когда пришла буква х, тогда добавляем в стек кортеж (1 1 1 1), тк и сууфикс и префикс и ответ и вся текущая               регулярка является последовательностью из 1 х;
//2 случай: когда пришла буква, но не х, тогда в стек добавляем (0 0 0 0), тк ни одна из величин не содержит х;
//3 случай: конкатенация ".", тогда происходит пересчет таким образом, что мы с последними двумя элементами из стека                  производим операцию и получаем новый элемент, добавляем такой элемент для префикса разберем, остальные значения                получаются похожим образом. Итак, префикс двух регулярных выражений получается из максимума по префикс первого                  РВ и суммы префикса второго РВ и числа букв х в случае, если второй РВ может состоять полнотсью из х;
//4 случай: "+", тогда пересчет похож на случай конкатенации, но там для всех значений вычисляется максимум из значения для            первой РВ и для второй
//5 случай: "*", для звезды Клини ситуация сложнее с вычислением к, если может регулярка состоять только из х, то есть может          быть максимальное к сразу бесконечным, или конечным, или нулем, или невозможным (-бесконечным), это очевидно                    вычисляется так: если старая регулярка не может быть хх...х, то и звезда не поможет, если 0, то 0, иначе берется                максимум из 0 и старого значения, остальные значения высчитываются очевидно аналогично "+"
//
//В каждом случае также необходимо проверить, что стек не пуст во время извлечения значений, тк податься может некорректное РВ