#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

string zamianaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

int obliczWystapieniaDanegoZnaku (string wyraz, int pozycjaZnaku)
{
    int iloscWystapien=1;

    if(wyraz.length() > pozycjaZnaku)
    {
        while(wyraz[pozycjaZnaku] == wyraz[pozycjaZnaku+1])
        {
            iloscWystapien++;
            pozycjaZnaku++;
        }
    }
    else
        iloscWystapien = 0;
    return iloscWystapien;
}

string skracanieWyrazow(string wyrazDoSkrocenia, int iloscZnakow)
{
    int dlugoscWyrazu = wyrazDoSkrocenia.length();
    int iloscWystapien = 1;
    //cin >> wyrazDoSkrocenia;

    //cout << wyrazDoSkrocenia << endl;

    for (int i=0; i<dlugoscWyrazu-2; i++)
    {
        if ((wyrazDoSkrocenia[i] == wyrazDoSkrocenia[i+1]) && (wyrazDoSkrocenia[i+1] == wyrazDoSkrocenia[i+2]))
        {
            iloscWystapien = obliczWystapieniaDanegoZnaku(wyrazDoSkrocenia, i);

            if(iloscWystapien >= iloscZnakow)
            {
                wyrazDoSkrocenia.replace(i,iloscWystapien,wyrazDoSkrocenia[i]+zamianaIntNaString(iloscWystapien));
            }
            dlugoscWyrazu = wyrazDoSkrocenia.length();
        }
    }
    return wyrazDoSkrocenia;
}

int main()
{
    //ifstream in("in.txt");
    //streambuf *cinbuf = cin.rdbuf(); //save old buf
    //cin.rdbuf(in.rdbuf()); //redirect cin to in.txt

    int iloscTestow;
    string wyraz;
    int znaki;

    cin >> iloscTestow;

    for (int i=0; i<iloscTestow; i++)
    {
        cin >> wyraz;
        cin >> znaki;
        cout << skracanieWyrazow(wyraz, znaki) << endl;
    }

    //cin.rdbuf(cinbuf); //reset to standard input again

    /*cin >> iloscTestow;
    for (int i=0; i<iloscTestow; i++)
    {
        cin >> wyraz;
        cin >> znaki;
        cout << skracanieWyrazow(wyraz, znaki) << endl;
    }*/




    /*string wyrazDoSkrocenia = "AAAAAAAABBBCCCCCC";
    int dlugoscWyrazu = wyrazDoSkrocenia.length();
    int iloscWystapien = 1;
    //cin >> wyrazDoSkrocenia;

    //cout << wyrazDoSkrocenia << endl;

    for (int i=0; i<dlugoscWyrazu-2; i++)
    {
        if ((wyrazDoSkrocenia[i] == wyrazDoSkrocenia[i+1]) && (wyrazDoSkrocenia[i+1] == wyrazDoSkrocenia[i+2]))
        {
            iloscWystapien = obliczWystapieniaDanegoZnaku(wyrazDoSkrocenia, i);
            wyrazDoSkrocenia.replace(i,iloscWystapien,wyrazDoSkrocenia[i]+zamianaIntNaString(iloscWystapien));
            dlugoscWyrazu = wyrazDoSkrocenia.length();
        }
    }
    cout << wyrazDoSkrocenia << endl;*/

    return 0;
}
