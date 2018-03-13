//
// Created by Adrian-Paul Florea on 12/13/17.
//

#ifndef TESTPROJECT_FRACTIE_H
#define TESTPROJECT_FRACTIE_H

class fr {
private:
    int a;
    int b;
public:
    int GetNumarator() { return a; }

    int GetNumitor() { return b; }

    void SetNumitor(int);

    void SetNumarator(int);

    void Simplifica();

    fr(int x = 0, int y = 1);
};

#endif //TESTPROJECT_FRACTIE_H
