
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
/*
Add or update the header of this file.
Rename this file to match this regular expression: "(([a-z_][a-z0-9_]*)|([A-Z][a-zA-Z0-9]+))$".
Add a new line at the end of this file.
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 */

#include <iostream>
#include <string>

using namespace std;

long long prhf(string S) {
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    for (int i = 0; i < n; i++) {
        int charValue;
        if (S[i] >= 'a' && S[i] <= 'z') {
            charValue = S[i] - 'a' + 1;
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            charValue = S[i] - 'A' + 27; 
        } else {
            charValue = 0;
        }
        valorHash = (valorHash + charValue * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash;
}

int main() {
    string input;
    cout << "Ingrese una cadena: ";
    getline(cin, input); 
    
    long long hashValue = prhf(input);
    cout << "El valor hash de la cadena es: " << hashValue << endl;

    return 0;
}


