#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string b;
    cin >> b;  // Lee la cadena de bits desde la entrada estándar

    int maxLen = 0; // Longitud máxima de la secuencia de 1s encontradas
    int leftCount = 0; // Longitud de la secuencia de 1s a la izquierda del 0
    int rightCount = 0; // Longitud de la secuencia de 1s a la derecha del 0
    int zeroPos = -1; // Posición del último 0 encontrado
    
    for (int i = 0; i < b.length(); i++) {
        // Contar la longitud de la secuencia de 1s a la derecha del último 0
        if (b[i] == '1') {
            rightCount++;
        } else {
            // Si encontramos un 0, actualizamos el máximo considerando el cambio
            if (zeroPos != -1) {
                maxLen = max(maxLen, leftCount + rightCount + 1);
            }
            // Actualizar los contadores
            leftCount = rightCount;
            rightCount = 0;
            zeroPos = i;
        }
    }
    
    // Comprobar la secuencia final, sin necesidad de cambiar un 0
    maxLen = max(maxLen, leftCount + rightCount + 1);
    
    cout << maxLen << endl;  // Imprime el resultado

    return 0;
}

