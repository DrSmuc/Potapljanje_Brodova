#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //deklaracije
    int player[12][12] = { 0 }, robot[12][12] = { 0 }, x, y, flagd = 0, flagc = 0, flagb = 0, rflagd = 0, rflagc = 0, rflagb = 0, rbrod = 5;
    int brod = 5, r, br = 1, br1 = 1, check[12][12] = { 0 }, rcheck[12][12] = { 0 };

    //brojaci brodova
    int br2 = 0, br5 = 0, br3 = 0, br6 = 0, br4 = 0, rbr2 = 0, rbr3 = 0, rbr4 = 0, rbr5 = 0, rbr6 = 0;
    int pk, pkr, hit = 0, smjer;  //smjer -> 1 (okomito) , 2 (vodoravno)

    char robovis[12][12], playervis[12][12] = { 0 };
    // 4(*1),3/6(*2),2/5(*2) brodovi
    srand(time(0));

    cout << "Imena brodova su 4(zauzima 4 polja), 3(zauzima 3 polja), 2(zauzima 2 polje), dva puta birate brodove 3 i 2." << endl << endl;

    //robot visual setup
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            robovis[i][j] = '0';

    //player setup
    for (int i = 0; i < 5;)
    {
        system("cls");

        //player vis setup
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 12; j++)
            {
                switch (player[i][j])
                {
                case 2:
                    playervis[i][j] = '2';
                    break;
                case 3:
                    playervis[i][j] = '3';
                    break;
                case 4:
                    playervis[i][j] = '4';
                    break;
                case 5:
                    playervis[i][j] = '2';
                    break;
                case 6:
                    playervis[i][j] = '3';
                    break;
                default:
                    playervis[i][j] = '0';
                }
            }
        }

        //player
        cout << " ";
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (i == 0)
                    cout << j << " ";
                else if (j == 0)
                {
                    if (i < 10)
                        cout << " " << i << " ";
                    else
                        cout << i << " ";
                }
                else if (j == 0 && i == 0)
                    cout << 0 << " ";
                else
                    cout << playervis[i][j] << " ";
            }
            cout << endl;
        }

        cout << "Koji brod zelite postaviti ?" << endl;
        cin >> brod;
        cout << "Kako ga zelite postaviti?" << endl;
        cin >> smjer;

        //okomito
        if (smjer == 1)
        {
            switch (brod)
            {
            case 4:
                if (flagd == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x + 1][y] == 0 && player[x + 2][y] == 0 && player[x + 3][y] == 0)
                    {
                        player[x][y] = 4;
                        player[x + 1][y] = 4;
                        player[x + 2][y] = 4;
                        player[x + 3][y] = 4;
                        flagd++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            case 3:
                if (flagc == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x + 1][y] == 0 && player[x + 2][y] == 0)
                    {
                        player[x][y] = 3;
                        player[x + 1][y] = 3;
                        player[x + 2][y] = 3;
                        flagc++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else if (flagc == 1)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x + 1][y] == 0 && player[x + 2][y] == 0)
                    {
                        player[x][y] = 6;
                        player[x + 1][y] = 6;
                        player[x + 2][y] = 6;
                        flagc++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            case 2:
                if (flagb == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x + 1][y] == 0)
                    {
                        player[x][y] = 2;
                        player[x + 1][y] = 2;
                        flagb++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else if (flagb == 1)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x + 1][y] == 0)
                    {
                        player[x][y] = 5;
                        player[x + 1][y] = 5;
                        flagb++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            default:
                cout << "Nije ime broda." << endl;
            }
        }


        //vodoravno
        if (smjer == 2)
        {
            switch (brod)
            {
            case 4:
                if (flagd == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x][y + 1] == 0 && player[x][y + 2] == 0 && player[x][y + 3] == 0)
                    {
                        player[x][y] = 4;
                        player[x][y + 1] = 4;
                        player[x][y + 2] = 4;
                        player[x][y + 3] = 4;
                        flagd++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            case 3:
                if (flagc == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x][y + 1] == 0 && player[x][y + 2] == 0)
                    {
                        player[x][y] = 3;
                        player[x][y + 1] = 3;
                        player[x][y + 2] = 3;
                        flagc++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else if (flagc == 1)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x][y + 1] == 0 && player[x][y + 2] == 0)
                    {
                        player[x][y] = 6;
                        player[x][y + 1] = 6;
                        player[x][y + 2] = 6;
                        flagc++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            case 2:
                if (flagb == 0)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x][y + 1] == 0)
                    {
                        player[x][y] = 2;
                        player[x][y + 1] = 2;
                        flagb++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else if (flagb == 1)
                {
                    cout << "Odaberi mjesto." << endl;
                    cin >> x >> y;
                    if (player[x][y] == 0 && player[x][y + 1] == 0)
                    {
                        player[x][y] = 5;
                        player[x][y + 1] = 5;
                        flagb++;
                        i++;
                    }
                    else
                        cout << "Zauzeto." << endl;
                }
                else
                    cout << "Veæ ste izabrali ovaj brod." << endl;
                break;
            default:
                cout << "Nije ime broda." << endl;
            }
        }
    }

    //player vis setup
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            switch (player[i][j])
            {
            case 2:
                playervis[i][j] = '2';
                break;
            case 3:
                playervis[i][j] = '3';
                break;
            case 4:
                playervis[i][j] = '4';
                break;
            case 5:
                playervis[i][j] = '2';
                break;
            case 6:
                playervis[i][j] = '3';
                break;
            default:
                playervis[i][j] = '0';
            }
        }
    }

 // robot setup
    for (int i = 0; i < 5;)
    {
        r = rand() % 4 + 2; // random.c od Damijanic
        smjer = rand() % 2 + 1;

 //okomito
        if (smjer == 1)
        {
            switch (r)
            {
            case 4:
                if (rflagd == 0)
                {
                    x = rand() % 7 + 1;
                    y = rand() % 10 + 1;
                    if (robot[x][y] == 0 && robot[x + 1][y] == 0 && robot[x + 2][y] ==
                        0 && robot[x + 3][y] == 0)
                    {
                        robot[x][y] = 4;
                        robot[x + 1][y] = 4;
                        robot[x + 2][y] = 4;
                        robot[x + 3][y] = 4;
                        rflagd++;
                        i++;
                    }
                }
                break;
            case 3:
                if (rflagc == 0)
                {
                    x = rand() % 8 + 1;
                    y = rand() % 10 + 1;
                    if (robot[x][y] == 0 && robot[x + 1][y] == 0 && robot[x + 2][y] == 0)
                    {
                        robot[x][y] = 3;
                        robot[x + 1][y] = 3;
                        robot[x + 2][y] = 3;
                        rflagc++;
                        i++;
                    }
                }
                else if (rflagc == 1)
                {
                    x = rand() % 8 + 1;
                    y = rand() % 10 + 1;
                    if (robot[x][y] == 0 && robot[x + 1][y] == 0 && robot[x + 2][y] == 0)
                    {
                        robot[x][y] = 6;
                        robot[x + 1][y] = 6;
                        robot[x + 2][y] = 6;
                        rflagc++;
                        i++;
                    }
                }
                break;
            case 2:
                if (rflagb == 0)
                {
                    x = rand() % 9 + 1;
                    y = rand() % 10 + 1;
                    if (robot[x][y] == 0 && robot[x + 1][y] == 0)
                    {
                        robot[x][y] = 2;
                        robot[x + 1][y] = 2;
                        rflagb++;
                        i++;
                    }
                    break;
                }
                else if (rflagb == 1)
                {
                    x = rand() % 9 + 1;
                    y = rand() % 10 + 1;
                    if (robot[x][y] == 0 && robot[x + 1][y] == 0)
                    {
                        robot[x][y] = 5;
                        robot[x + 1][y] = 5;
                        rflagb++;
                        i++;
                    }
                }
            }
        }


 //vodoravno
        if (smjer == 2)
        {
            switch (r)
            {
            case 4:
                if (rflagd == 0)
                {
                    x = rand() % 10 + 1;
                    y = rand() % 7 + 1;
                    if (robot[x][y] == 0 && robot[x][y + 1] == 0 && robot[x][y + 2] == 0 && robot[x][y + 3] == 0)
                    {
                        robot[x][y] = 4;
                        robot[x][y + 1] = 4;
                        robot[x][y + 2] = 4;
                        robot[x][y + 3] = 4;
                        rflagd++;
                        i++;
                    }
                }
                break;
            case 3:
                if (rflagc == 0)
                {
                    x = rand() % 10 + 1;
                    y = rand() % 8 + 1;
                    if (robot[x][y] == 0 && robot[x][y + 1] == 0 && robot[x][y + 2] == 0)
                    {
                        robot[x][y] = 3;
                        robot[x][y + 1] = 3;
                        robot[x][y + 2] = 3;
                        rflagc++;
                        i++;
                    }
                }
                else if (rflagc == 1)
                {
                    x = rand() % 10 + 1;
                    y = rand() % 8 + 1;
                    if (robot[x][y] == 0 && robot[x][y + 1] == 0 && robot[x][y + 2] == 0)
                    {
                        robot[x][y] = 6;
                        robot[x][y + 1] = 6;
                        robot[x][y + 2] = 6;
                        rflagc++;
                        i++;
                    }
                }
                break;
            case 2:
                if (rflagb == 0)
                {
                    x = rand() % 10 + 1;
                    y = rand() % 9 + 1;
                    if (robot[x][y] == 0 && robot[x][y + 1] == 0)
                    {
                        robot[x][y] = 2;
                        robot[x][y + 1] = 2;
                        rflagb++;
                        i++;
                    }
                    break;
                }
                else if (rflagb == 1)
                {
                    x = rand() % 10 + 1;
                    y = rand() % 9 + 1;
                    if (robot[x][y] == 0 && robot[x][y + 1] == 0)
                    {
                        robot[x][y] = 5;
                        robot[x][y + 1] = 5;
                        rflagb++;
                        i++;
                    }
                }
            }
        }
    }
 
 //pocetni screen
    system("cls");

 //robot
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i == 0)
                cout << j << " ";
            else if (j == 0)
                cout << " " << i << " ";
            else if (j == 0 && i == 0)
                cout << 0 << " ";
            else
                cout << robovis[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n-\n\n";

 //player
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            if (i == 0)
                cout << j << " ";
            else if (j == 0)
                cout << " " << i << " ";
            else if (j == 0 && i == 0)
                cout << 0 << " ";
            else
                cout << playervis[i][j] << " ";
        }
        cout << endl;
    }

 //game
    while ((rbrod > 0) || (brod > 0)) {

     //player turn
        for (int i = 0; i == 0;)
        {
            cout << "Odaberi gdje cete pogoditi:" << endl;
            cin >> x >> y;
            if (check[x][y] == 0)
            {
                check[x][y] = 1;
                if (robot[x][y] != 0)
                {
                    switch (robot[x][y])
                    {
                    case 2:
                        robovis[x][y] = 'X';
                        br2++;
                        break;
                    case 3:
                        robovis[x][y] = 'X';
                        br3++;
                        break;
                    case 4:
                        robovis[x][y] = 'X';
                        br4++;
                        break;
                    case 5:
                        robovis[x][y] = 'X';
                        br5++;
                        break;
                    case 6:
                        robovis[x][y] = 'X';
                        br6++;
                        break;
                    }
                }
                else
                {
                    robovis[x][y] = '*';
                    i++;
                }

            }
            else
                cout<<"vec ste tu pogodili."<<endl;
        }


     //robot turn
        for (int i = 0; i == 0;)
        {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
            if (rcheck[x][y] == 0)
            {
                rcheck[x][y] = 1;
                if (player[x][y] != 0)
                {
                    switch (player[x][y])
                    {
                    case 2:
                        playervis[x][y] = 'X';
                        rbr2++;
                        break;
                    case 3:
                        playervis[x][y] = 'X';
                        rbr3++;
                        break;
                    case 4:
                        playervis[x][y] = 'X';
                        rbr4++;
                        break;
                    case 5:
                        playervis[x][y] = 'X';
                        rbr5++;
                        break;
                    case 6:
                        playervis[x][y] = 'X';
                        rbr6++;
                        break;
                    }
                }
                else
                {
                    playervis[x][y] = '*';
                    i++;
                }
            }
        }


        system("cls");

     //robot tablica
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (i == 0)
                    cout << j << " ";
                else if (j == 0)
                    cout << i << " ";
                else if (j == 0 && i == 0)
                    cout << 0 << " ";
                else
                    cout << robovis[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\n-\n\n";

     //player tablica    
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                if (i == 0)
                    cout << j << " ";
                else if (j == 0)
                    cout << " " << i << " ";
                else if (j == 0 && i == 0)
                    cout << 0 << " ";
                else
                    cout << playervis[i][j];
            }
            cout << endl;
        }

        cout << endl;

    //robot brod potpljen?
    if (br2 == 2)
    {
        cout << "Brod 2 je potopljen" << endl;
        br2++;
        rbrod--;
    }
    else if (br3 == 3)
    {
        cout << "Brod 3 je potopljen" << endl ;
        br3++;
        rbrod--;
    }
    else if (br4 == 4)
    {
        cout << "Brod 4 je potopljen" << endl;
        br4++;
        rbrod--;
    }
    else if (br5 == 2)
    {
        cout << "Brod 2 je potopljen" << endl;
        br5++;
        rbrod--;
    }
    else if (br6 == 3)
    {
        cout << "Brod 3 je potopljen";
        br6++;
        rbrod--;
    }

 //player brod potopljen?
    if (rbr2 == 2)
    {
        cout << "Vas Brod 2 je potopljen" << endl;
        rbr2++;
        brod--;
    }
    if (rbr3 == 3)
    {
        cout << "Vas Brod 3 je potopljen" << endl;
        rbr3++;
        brod--;
    }
    if (rbr4 == 4)
    {
        cout << "Vas Brod 4 je potopljen" << endl;
        rbr4++;
        brod--;
    }
    if (rbr5 == 2)
    {
        cout << "Brod 2 playera  je potopljen" << endl;
        rbr5++;
        brod--;
    }
    if (rbr6 == 3)
    {
        cout << "Brod 3 playera  je potopljen" << endl;
        rbr6++;
        brod--;
    }

  } 

  system("cls");
  if (rbrod <= 0)
      cout << "Vi ste pobjedili :D";
  if (brod <= 0)
      cout << "Izgubili ste >:)";
  return 0;
}

