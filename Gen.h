#ifndef C___LEARN_GEN_H
#define C___LEARN_GEN_H

class Gen {
private:
    bool **tablero;
    int size;
public:
    Gen() = default;;

    Gen(int x) {
        size = x;
        tablero = new bool *[size];
        for (int i = 0; i < size; ++i) {
            tablero[i] = new bool[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 10; j++) {
                tablero[i][j] = false;
            }
        }
    }

    virtual ~Gen() = default;

    bool **getTablero() {
        return tablero;
    }

    void setCell(int x, int y, bool state) {
        tablero[x][y] = state;
    }

    int check(int x, int y) {
        int cont = 0;
        for (int i = x - 1; i < x + 2; i++) {
            for (int j = y - 1; j < y + 2; j++) {
                if (i >= 0 && i < size && j >= 0 && j < size && (i != x || j != y) && tablero[i][j]) {
                    cont++;
                }
            }
        }
        return cont;
    }

    bool operator==(const Gen &rhs) const {
        return tablero == rhs.tablero && size == rhs.size;
    }

    bool operator!=(const Gen &rhs) const {
        return !(rhs == *this);
    }

    void next() {
        bool **tableroAux;
        int cont = 0;
        tableroAux = new bool *[size];
        for (int i = 0; i < size; ++i) {
            tableroAux[i] = new bool[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 10; j++) {
                tableroAux[i][j] = tablero[i][j];
            }
        }
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cont = check(i, j);
                if (tablero[i][j] && (cont < 2 || cont > 3)) {
                    tableroAux[i][j] = false;
                } else if (!tablero[i][j] && cont == 3) {
                    tableroAux[i][j] = true;
                }
            }
        }
        tablero=tableroAux;
    }

    void show() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << tablero[i][j];
            }
            std::cout << std::endl;
        }
    }

};

#endif //C___LEARN_GEN_H
