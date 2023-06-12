#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


bool check1(int x, int y, int smjer, int ch)
{
    switch (ch)
    {
    case 2:
        if ((x < 10 && smjer != 2 && x>0) || (y < 10 && smjer != 1 && y>0))
            return 1; break;
    case 3:
        if ((x < 9 && smjer != 2 && x>0) || (y < 9 && smjer != 1 && y>0)) return 1;             break;
    case 4:
        if ((x < 8 && smjer != 2 && x>0) || (y < 8 && smjer != 1 && y>0)) return 1;
    }
    return 0;
}




int main()
{
    //deklaracije
    int player[12][12] = { 0 }, robot[12][12] = { 0 }, x, y, flagd = 0, flagc = 0, flagb = 0, rflagd = 0, rflagc = 0, rflagb = 0, rbrod = 5;
    int brod = 5, r, br = 1, br1 = 1, check[12][12] = { 0 }, rcheck[12][12] = { 0 }, option = 4;

    //brojaci brodova
    int br2 = 0, br5 = 0, br3 = 0, br6 = 0, br4 = 0, rbr2 = 0, rbr3 = 0, rbr4 = 0, rbr5 = 0, rbr6 = 0;
    int ch = 0;   //koji brod?
    int pk, pkr, hit = 0, counter = 0, smjer, sm, mjesto[4] = {0};  //smjer -> 1 (okomito) , 2 (vodoravno)

    char robovis[12][12];
    char playervis[12][12] = { 0 };

    // 4(*1),3/6(*2),2/5(*2) brodovi
    srand(time(0));


    //datoteke
    fstream playerBrod;
    fstream robotBrod;
    fstream robotMemory;
    fstream Ppogodak; //BINARNO
    fstream Rpogodak; //BINARNO  


    cout << "Imena brodova su 4(zauzima 4 polja), 3(zauzima 3 polja), 2(zauzima 2 polje), dva puta     birate brodove 3 i 2." << endl;

    cout << "Brod mozete postaviti okomito (1) i vodoravno (2)" << endl << endl;

    //robot visual setup
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            robovis[i][j] = '0';
    //start menu

    cout << "Dobro dosli u POTAPANJE BRODOVA\n" << "Sto zelite napraviti?\n\n\n" << "Start new game(0)" << endl << "Continue game(1)" << endl << "Exit(2)" << endl;
    cin >> option;
    switch (option)
    {
    case 0:
        playerBrod.open("player_brod.txt", ios::out);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                playerBrod << 0 << " ";
        playerBrod.close();
        break;
    case 1:
        break;
    case 2:
        return 0;
        break;
    default:cout << "Nije opcija!"; break;

    }


    //player setup
    if (option == 0)
    {
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
            playerBrod.close();

            //player
            playerBrod.open("player_brod.txt", ios::out);
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
                            if (check1(x, y, 1, 4))
                            {
                                player[x][y] = 4;
                                player[x + 1][y] = 4;
                                player[x + 2][y] = 4;
                                player[x + 3][y] = 4;
                                flagd++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 1, 3))
                            {
                                player[x][y] = 3;
                                player[x + 1][y] = 3;
                                player[x + 2][y] = 3;
                                flagc++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 1, 3))
                            {
                                player[x][y] = 6;
                                player[x + 1][y] = 6;
                                player[x + 2][y] = 6;
                                flagc++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 1, 2))
                            {
                                player[x][y] = 2;
                                player[x + 1][y] = 2;
                                flagb++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 1, 2))
                            {
                                player[x][y] = 5;
                                player[x + 1][y] = 5;
                                flagb++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 2, 4))
                            {
                                player[x][y] = 4;
                                player[x][y + 1] = 4;
                                player[x][y + 2] = 4;
                                player[x][y + 3] = 4;
                                flagd++;
                                i++;
                            }
                            else
                                cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 2, 3))
                            {
                                player[x][y] = 3;
                                player[x][y + 1] = 3;
                                player[x][y + 2] = 3;
                                flagc++;
                                i++;
                            }
                            else
                                cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 2, 3))
                            {
                                player[x][y] = 6;
                                player[x][y + 1] = 6;
                                player[x][y + 2] = 6;
                                flagc++;
                                i++;
                            }
                            else
                                cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 2, 2))
                            {
                                player[x][y] = 2;
                                player[x][y + 1] = 2;
                                flagb++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
                            if (check1(x, y, 2, 2))
                            {
                                player[x][y] = 5;
                                player[x][y + 1] = 5;
                                flagb++;
                                i++;
                            }
                            else cout << "Izvan polja" << endl;
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
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                playerBrod << player[i][j] << " ";
        playerBrod.close();

        //player vis setup
        playerBrod.open("player_brod.txt", ios::in);
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
        playerBrod.close();


        // robot setup
        for (int i = 0; i < 5;)
        {
            r = rand() % 4 + 2;   // random.c od Damijanic
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
        robotBrod.open("robot_brod.txt", ios::out);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                robotBrod << robot[i][j] << " ";
        robotBrod.close();
    }








    system("cls");

    //visual setup
    robotBrod.open("robot_brod.txt", ios::in);
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            robotBrod >> robot[i][j];
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            switch (robot[i][j])
            {
            case 2:
                robovis[i][j] = '0';
                break;
            case 3:
                robovis[i][j] = '0';
                break;
            case 4:
                robovis[i][j] = '0';
                break;
            case 5:
                robovis[i][j] = '0';
                break;
            case 6:
                robovis[i][j] = '0';
                break;
            default:
                robovis[i][j] = '0';
            }
        }
    }
    cout << "\n-\n\n";
    robotBrod.close();


    playerBrod.open("player_brod.txt", ios::in);
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            playerBrod >> player[i][j];

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
    playerBrod.close();

    if (option == 1)
    {
        Ppogodak.open("Ppogodak.bin", ios::binary | ios::in);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                Ppogodak.read((char*)&check[i][j], sizeof(1));
        Ppogodak.close();
        Rpogodak.open("Rpogodak.bin", ios::binary | ios::in);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                Rpogodak.read((char*)&rcheck[i][j], sizeof(1));
        Rpogodak.close();
        //checjk ateup2
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                if (check[i][j] == 1)
                {
                    if (robot[i][j] != 0)
                    {
                        switch (robot[i][j])
                        {
                        case 2:
                            robovis[i][j] = 'X';
                            br2++;
                            break;
                        case 3:
                            robovis[i][j] = 'X';
                            br3++;
                            break;
                        case 4:
                            robovis[i][j] = 'X';
                            br4++;
                            break;
                        case 5:
                            robovis[i][j] = 'X';
                            br5++;
                            break;
                        case 6:
                            robovis[i][j] = 'X';
                            br6++;
                            break;
                        }
                    }
                    else
                    {
                        robovis[i][j] = '*';
                    }
                }


        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                if (rcheck[i][j] == 1)
                {
                    if (player[i][j] != 0)
                    {
                        switch (player[i][j])
                        {
                        case 2:
                            playervis[i][j] = 'X';
                            rbr2++;
                            break;
                        case 3:
                            playervis[i][j] = 'X';
                            rbr3++;
                            break;
                        case 4:
                            playervis[i][j] = 'X';
                            rbr4++;
                            break;
                        case 5:
                            playervis[i][j] = 'X';
                            rbr5++;
                            break;
                        case 6:
                            playervis[i][j] = 'X';
                            rbr6++;
                            break;
                        }
                    }
                    else
                    {
                        playervis[i][j] = '*';
                    }
                }


        // ai za robota
        robotMemory.open("Memory.txt", ios::in);
        for (int i = 0; i < 4; i++)
            robotMemory >> mjesto[i];
        robotMemory >> counter;
        robotMemory >> sm;
        robotMemory.close();
            

    }


   //pocetni screen
    system("cls");





    //game
    while ((rbrod > 0) || (brod > 0)) {

        //player turn
        for (int k = 0; k == 0;)
        {

            //robot
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
                        cout << robovis[i][j] << " ";
                }
                cout << endl;
            }
            cout << "\n-\n\n";
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
                        if (br2 == 2)
                        {
                            system("cls");
                            cout << "Brod 12 je potopljen" << endl;
                            br2++;
                            rbrod--;
                        }
                        break;
                    case 3:
                        robovis[x][y] = 'X';
                        br3++;
                        if (br3 == 3)
                        {
                            system("cls");
                            cout << "Brod 3 je potopljen" << endl;
                            br3++;
                            rbrod--;
                        }

                        break;
                    case 4:
                        robovis[x][y] = 'X';
                        br4++;
                        if (br4 == 4)
                        {
                            system("cls");
                            br4++;
                            cout << "Brod 4 je potopljen" << endl;
                            rbrod--;
                        }

                        break;
                    case 5:
                        robovis[x][y] = 'X';
                        br5++;
                        if (br5 == 2)
                        {
                            system("cls");
                            br5++;
                            cout << "Brod 2 je potopljen" << endl;
                            rbrod--;
                        }

                        break;
                    case 6:
                        robovis[x][y] = 'X';
                        br6++;
                        if (br6 == 3)
                        {
                            system("cls");
                            cout << "Brod 3 je potopljen" << endl;
                            br6++;
                            rbrod--;
                        }

                        break;
                    }
                }
                else
                {
                    robovis[x][y] = '*';
                    k++;
                    system("cls");
                }


                if (rbrod <= 0)
                {
                    cout << "Vi ste pobjedili :D";
                    return 0;
                    // BIN datoteka za check pobjede molim te napravi
                }

            }
            else
            {
                system("cls");
                cout << endl << endl << "vec ste tu pogodili." << endl << endl << endl;

            }

            Ppogodak.open("Ppogodak.bin", ios::binary | ios::out);
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 11; j++)
                    Ppogodak.write((char*)&check[i][j], sizeof(1));
            Ppogodak.close();

        }




        //robot turn
        for (int k = 0; k == 0;)
        {
            //if (counter == 0)
            //{
                sm = 0;
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
                            if (rbr2 < 2)
                            {
                                hit = 2;
                                counter = 1;
                            }
                            break;
                        case 3:
                            playervis[x][y] = 'X';
                            rbr3++;
                            if (rbr3 < 3)
                            {
                                hit = 3;
                                counter = 3-rbr3;
                            }
                            break;
                        case 4:
                            playervis[x][y] = 'X';
                            rbr4++;
                            if (rbr4 < 4)
                            {
                                hit = 4;
                                counter = 4-rbr4;
                            }
                            break;
                        case 5:
                            playervis[x][y] = 'X';
                            rbr5++;
                            if (rbr5 < 2)
                            {
                                hit = 5;
                                counter = 2 -rbr5;
                            }
                            break;
                        case 6:
                            playervis[x][y] = 'X';
                            rbr6++;
                            if (rbr6 < 3)
                            {
                                hit = 6;
                                counter = 3 - rbr6;
                            }
                            break;
                        }
                    }
                    else
                    {
                        playervis[x][y] = '*';
                        k++;
                    }
                }
            //}
/*else
            {
                switch (hit)
                {
                case 2:
                    
                    if (sm == 1 && x < 10 && mjesto[0] == 0)
                    {
                        mjesto[0] = 1;
                        if (rcheck[x + 1][y] == 0)
                        {
                            rcheck[x + 1][y] = 1;
                            if (player[x + 1][y] != 0)
                            {
                                switch (player[x + 1][y])
                                {
                                case 2:
                                    playervis[x + 1][y] = 'X';
                                    rbr2++;
                                    counter--;
                                    break;
                                case 3:
                                    playervis[x + 1][y] = 'X';
                                    rbr3++;
                                    break;
                                case 4:
                                    playervis[x + 1][y] = 'X';
                                    rbr4++;
                                    break;
                                case 5:
                                    playervis[x + 1][y] = 'X';
                                    rbr5++;
                                    break;
                                case 6:
                                    playervis[x + 1][y] = 'X';
                                    rbr6++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x + 1][y] = '*';
                                sm++;
                                k++;
                            }
                        }
                    }
                    else if (sm == 2 && x > 1 && mjesto[1] == 0)
                    {
                        mjesto[1] = 1;
                        if (rcheck[x - 1][y] == 0)
                        {
                            rcheck[x - 1][y] = 1;
                            if (player[x - 1][y] != 0)
                            {
                                switch (player[x - 1][y])
                                {
                                case 2:
                                    playervis[x - 1][y] = 'X';
                                    rbr2++;
                                    counter--;
                                    break;
                                case 3:
                                    playervis[x - 1][y] = 'X';
                                    rbr3++;
                                    break;
                                case 4:
                                    playervis[x - 1][y] = 'X';
                                    rbr4++;
                                    break;
                                case 5:
                                    playervis[x - 1][y] = 'X';
                                    rbr5++;
                                    break;
                                case 6:
                                    playervis[x - 1][y] = 'X';
                                    rbr6++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x - 1][y] = '*';
                                sm++;
                                k++;
                            }
                        }
                    }
                    else if (sm == 3 && y < 10 && mjesto[2] == 0)
                    {
                        mjesto[2] = 1;
                        if (rcheck[x][y + 1] == 0)
                        {
                            rcheck[x][y + 1] = 1;
                            if (player[x][y + 1] != 0)
                            {
                                switch (player[x][y + 1])
                                {
                                case 2:
                                    playervis[x][y + 1] = 'X';
                                    rbr2++;
                                    counter--;
                                    break;
                                case 3:
                                    playervis[x][y + 1] = 'X';
                                    rbr3++;
                                    break;
                                case 4:
                                    playervis[x][y + 1] = 'X';
                                    rbr4++;
                                    break;
                                case 5:
                                    playervis[x][y + 1] = 'X';
                                    rbr5++;
                                    break;
                                case 6:
                                    playervis[x][y + 1] = 'X';
                                    rbr6++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y + 1] = '*';
                                sm++;
                                k++;
                            }
                        }
                    }
                    else if (sm == 4 && y > 1 && mjesto[3] == 0)
                    {
                        mjesto[3] = 1;
                        if (rcheck[x][y - 1] == 0)
                        {
                            rcheck[x][y - 1] = 1;
                            if (player[x][y - 1] != 0)
                            {
                                switch (player[x][y - 1])
                                {
                                case 2:
                                    playervis[x][y - 1] = 'X';
                                    rbr2++;
                                    counter--;
                                    break;
                                case 3:
                                    playervis[x][y - 1] = 'X';
                                    rbr3++;
                                    break;
                                case 4:
                                    playervis[x][y - 1] = 'X';
                                    rbr4++;
                                    break;
                                case 5:
                                    playervis[x][y - 1] = 'X';
                                    rbr5++;
                                    break;
                                case 6:
                                    playervis[x][y - 1] = 'X';
                                    rbr6++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y - 1] = '*';
                                sm++;
                                k++;
                            }
                        }
                    }
                    else mjesto[sm - 1] = 1; break;
                case 3:
                    
                    if (sm == 1 && x < 10 && mjesto[0] == 0)
                    {
                        if (rcheck[x + 1][y] == 0)
                        {
                            rcheck[x + 1][y] = 1;
                            if (player[x + 1][y] != 0)
                            {
                                switch (player[x + 1][y])
                                {
                                case 2:
                                    playervis[x + 1][y] = 'X';
                                    rbr2++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x + 1][y] = 'X';
                                    rbr3++;
                                    x = x + 1;
                                    sm = 1;
                                    counter--;
                                    break;
                                case 4:
                                    playervis[x + 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[0] = 1;
                                    break;
                                case 5:
                                    playervis[x + 1][y] = 'X';
                                    rbr5++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                case 6:
                                    playervis[x + 1][y] = 'X';
                                    rbr6++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x + 1][y] = '*';
                                if (counter < 2)
                                {
                                    sm = 2; x = x - 1;
                                }
                                else
                                    sm = 0;
                                mjesto[0] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 2 && x > 1 && mjesto[1] == 0)
                    {
                        
                        if (rcheck[x - 1][y] == 0)
                        {
                            rcheck[x - 1][y] = 1;
                            if (player[x - 1][y] != 0)
                            {
                                switch (player[x - 1][y])
                                {
                                case 2:
                                    playervis[x - 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 3:
                                    playervis[x - 1][y] = 'X';
                                    rbr3++;
                                    x = x - 1;
                                    sm = 2;
                                    counter--;
                                    break;
                                case 4:
                                    playervis[x - 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 5:
                                    playervis[x - 1][y] = 'X';
                                    rbr5++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 6:
                                    playervis[x - 1][y] = 'X';
                                    rbr6++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x - 1][y] = '*';
                                if (counter < 2)
                                {
                                    sm = 1; x = x + 1;
                                }
                                else
                                    sm = 0;
                                mjesto[1] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 3 && y < 10 && mjesto[2] == 0)
                    {
                        
                        if (rcheck[x][y + 1] == 0)
                        {
                            rcheck[x][y + 1] = 1;
                            if (player[x][y + 1] != 0)
                            {
                                switch (player[x][y + 1])
                                {
                                case 2:
                                    playervis[x][y + 1] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 3:
                                    playervis[x][y + 1] = 'X';
                                    rbr3++;
                                    counter--;
                                    y = y + 1;
                                    sm = 3;
                                    break;
                                case 4:
                                    playervis[x][y + 1] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 5:
                                    playervis[x][y + 1] = 'X';
                                    rbr5++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 6:
                                    playervis[x][y + 1] = 'X';
                                    rbr6++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y + 1] = '*';
                                if (counter < 2)
                                {
                                    sm = 4; y = y - 1;
                                }
                                else
                                    sm = 0;
                                mjesto[2] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 4 && y > 1 && mjesto[3] == 0)
                    {
                        
                        if (rcheck[x][y - 1] == 0)
                        {
                            rcheck[x][y - 1] = 1;
                            if (player[x][y - 1] != 0)
                            {
                                switch (player[x][y - 1])
                                {
                                case 2:
                                    playervis[x][y - 1] = 'X';
                                    rbr2++;
                                    sm--;
                                    mjesto[3] = 1;
                                    break;
                                case 3:
                                    playervis[x][y - 1] = 'X';
                                    rbr3++;
                                    counter--;
                                    y = y - 1; 
                                    sm = 4; 
                                    break;
                                case 4:
                                    playervis[x][y - 1] = 'X';
                                    rbr4++;
                                    mjesto[3] = 1;
                                    sm--;
                                    break;
                                case 5:
                                    playervis[x][y - 1] = 'X';
                                    rbr5++;
                                    mjesto[3] = 1;
                                    sm--;
                                    break;
                                case 6:
                                    playervis[x][y - 1] = 'X';
                                    rbr6++;
                                    mjesto[3] = 1;
                                    sm--;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y - 1] = '*';
                                if (counter < 2)
                                {
                                    sm = 3; y = y - 1;
                                }
                                else
                                    sm = 0;
                                mjesto[3] = 1;
                                k++;
                            }
                        }
                    }
                    else mjesto[sm - 1] = 1; break;
                case 4:
                    sm++;
                    if (sm == 1 && x < 10 && mjesto[0] == 0)
                    {
                        if (rcheck[x + 1][y] == 0)
                        {
                            rcheck[x + 1][y] = 1;
                            if (player[x + 1][y] != 0)
                            {
                                switch (player[x + 1][y])
                                {
                                case 2:
                                    playervis[x + 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[0] = 1;
                                    break;
                                case 3:
                                    playervis[x + 1][y] = 'X';
                                    rbr3++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x + 1][y] = 'X';
                                    rbr4++;
                                    counter--;
                                    x = x + 1;
                                    sm = 1;
                                    break;
                                case 5:
                                    playervis[x + 1][y] = 'X';
                                    rbr5++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                case 6:
                                    playervis[x + 1][y] = 'X';
                                    rbr6++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x + 1][y] = '*';
                                if (counter == 2)
                                {
                                    sm = 2; y = y + 1;
                                }
                                else if (counter == 1)
                                {
                                    sm = 2; y = y + 2;
                                }
                                else
                                    sm = 0;
                                mjesto[0] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 2 && x > 1 && mjesto[1] == 0)
                    {
                        if (rcheck[x - 1][y] == 0)
                        {
                            rcheck[x - 1][y] = 1;
                            if (player[x - 1][y] != 0)
                            {
                                switch (player[x - 1][y])
                                {
                                case 2:
                                    playervis[x - 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 3:
                                    playervis[x - 1][y] = 'X';
                                    rbr3++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 4:
                                    playervis[x - 1][y] = 'X';
                                    rbr4++;
                                    x = x - 1;
                                    sm = 2;
                                    counter--;
                                    break;
                                case 5:
                                    playervis[x - 1][y] = 'X';
                                    rbr5++;
                                    mjesto[1] = 1;
                                    sm++;
                                    break;
                                case 6:
                                    playervis[x - 1][y] = 'X';
                                    rbr6++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x - 1][y] = '*';
                                if (counter == 2)
                                {
                                    sm = 1; x = x + 1;
                                }
                                else if (counter == 1)
                                {
                                    sm = 1; x = x + 2;
                                }
                                else
                                    sm = 0;
                                mjesto[1] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 3 && y < 10 && mjesto[2] == 0)
                    {
                        if (rcheck[x][y + 1] == 0)
                        {
                            rcheck[x][y + 1] = 1;
                            if (player[x][y + 1] != 0)
                            {
                                switch (player[x][y + 1])
                                {
                                case 2:
                                    playervis[x][y + 1] = 'X';
                                    rbr2++;
                                    mjesto[2] = 1;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x][y + 1] = 'X';
                                    rbr3++;
                                    mjesto[2] = 1;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x][y + 1] = 'X';
                                    rbr4++;
                                    y = y + 1;
                                    sm = 3;
                                    counter--;
                                    break;
                                case 5:
                                    playervis[x][y + 1] = 'X';
                                    rbr5++;
                                    mjesto[2] = 1;
                                    sm++;
                                    break;
                                case 6:
                                    playervis[x][y + 1] = 'X';
                                    rbr6++;
                                    mjesto[2] = 1;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y + 1] = '*';
                                if (counter == 2)
                                {
                                    sm = 4; y = y - 1;
                                }
                                else if (counter == 1)
                                {
                                    sm = 4; y = y - 2;
                                }
                                else
                                    sm = 0;
                                mjesto[2] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 4 && y > 1 && mjesto[3] == 0)
                    {
                        
                        if (rcheck[x][y - 1] == 0)
                        {
                            rcheck[x][y - 1] = 1;
                            if (player[x][y - 1] != 0)
                            {
                                switch (player[x][y - 1])
                                {
                                case 2:
                                    playervis[x][y - 1] = 'X';
                                    rbr2++;
                                    mjesto[3] = 1;
                                    sm--;
                                    break;
                                case 3:
                                    playervis[x][y - 1] = 'X';
                                    rbr3++;
                                    sm--;
                                    mjesto[3] = 1;
                                    break;
                                case 4:
                                    playervis[x][y - 1] = 'X';
                                    rbr4++;
                                    y = y - 1;
                                    counter--;
                                    break;
                                case 5:
                                    playervis[x][y - 1] = 'X';
                                    rbr5++;
                                    mjesto[3] = 1;
                                    sm--;                                    break;
                                case 6:
                                    playervis[x][y - 1] = 'X';
                                    rbr6++;
                                    mjesto[3] = 1;
                                    sm--;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y - 1] = '*';
                                if (counter == 2)
                                {
                                    sm = 3; y = y + 1;
                                }
                                else if (counter == 1)
                                {
                                    sm = 3; y = y + 2;
                                }
                                else
                                    sm = 0;
                                mjesto[3] = 1;
                                k++;
                            }
                        }
                    }
                    else mjesto[sm - 1] = 1; break;

                case 5:
                    sm++;
                    if (sm == 1 && x < 10 && mjesto[0] == 0)
                    {
                        mjesto[0] = 1;
                        if (rcheck[x + 1][y] == 0)
                        {
                            rcheck[x + 1][y] = 1;
                            if (player[x + 1][y] != 0)
                            {
                                switch (player[x + 1][y])
                                {
                                case 2:
                                    playervis[x + 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x + 1][y] = 'X';
                                    rbr3++;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x + 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    break;
                                case 5:
                                    playervis[x + 1][y] = 'X';
                                    rbr5++;
                                    counter--;
                                    break;
                                case 6:
                                    playervis[x + 1][y] = 'X';
                                    rbr6++;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x + 1][y] = '*';
                                k++;
                            }
                        }
                    }
                    else if (sm == 2 && x > 1 && mjesto[1] == 0)
                    {
                        mjesto[1] = 1;
                        if (rcheck[x - 1][y] == 0)
                        {
                            rcheck[x - 1][y] = 1;
                            if (player[x - 1][y] != 0)
                            {
                                switch (player[x - 1][y])
                                {
                                case 2:
                                    playervis[x - 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x - 1][y] = 'X';
                                    rbr3++;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x - 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    break;
                                case 5:
                                    playervis[x - 1][y] = 'X';
                                    rbr5++;
                                    counter--;
                                    break;
                                case 6:
                                    playervis[x - 1][y] = 'X';
                                    rbr6++;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x - 1][y] = '*';
                                k++;
                            }
                        }
                    }
                    else if (sm == 3 && y < 10 && mjesto[2] == 0)
                    {
                        mjesto[2] = 1;
                        if (rcheck[x][y + 1] == 0)
                        {
                            rcheck[x][y + 1] = 1;
                            if (player[x][y + 1] != 0)
                            {
                                switch (player[x][y + 1])
                                {
                                case 2:
                                    playervis[x][y + 1] = 'X';
                                    rbr2++;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x][y + 1] = 'X';
                                    rbr3++;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x][y + 1] = 'X';
                                    rbr4++;
                                    sm++;
                                    break;
                                case 5:
                                    playervis[x][y + 1] = 'X';
                                    rbr5++;
                                    counter--;
                                    break;
                                case 6:
                                    playervis[x][y + 1] = 'X';
                                    rbr6++;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y + 1] = '*';
                                k++;
                            }
                        }
                    }
                    else if (sm == 4 && y > 1 && mjesto[3] == 0)
                    {
                        mjesto[3] = 1;
                        if (rcheck[x][y - 1] == 0)
                        {
                            rcheck[x][y - 1] = 1;
                            if (player[x][y - 1] != 0)
                            {
                                switch (player[x][y - 1])
                                {
                                case 2:
                                    playervis[x][y - 1] = 'X';
                                    rbr2++;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x][y - 1] = 'X';
                                    rbr3++;
                                    sm++;
                                    break;
                                case 4:
                                    playervis[x][y - 1] = 'X';
                                    rbr4++;
                                    sm++;
                                    break;
                                case 5:
                                    playervis[x][y - 1] = 'X';
                                    rbr5++;
                                    counter--;
                                    break;
                                case 6:
                                    playervis[x][y - 1] = 'X';
                                    rbr6++;
                                    sm++;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y - 1] = '*';
                                k++;
                            }
                        }
                    }
                    else mjesto[sm - 1] = 1; break;
                case 6:
                    if (sm == 1 && x < 10 && mjesto[0] == 0)
                    {
                        if (rcheck[x + 1][y] == 0)
                        {
                            rcheck[x + 1][y] = 1;
                            if (player[x + 1][y] != 0)
                            {
                                switch (player[x + 1][y])
                                {
                                case 2:
                                    playervis[x + 1][y] = 'X';
                                    rbr2++;
                                    mjesto[0] = 1;
                                    sm++;
                                    break;
                                case 3:
                                    playervis[x + 1][y] = 'X';
                                    rbr3++;
                                    sm++;
                                    mjesto[0] = 1;
                                    break;
                                case 4:
                                    playervis[x + 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[0] = 1;
                                    break;
                                case 5:
                                    playervis[x + 1][y] = 'X';
                                    rbr5++;
                                    sm++;
                                    mjesto[0] = 1;
                                    break;
                                case 6:
                                    playervis[x + 1][y] = 'X';
                                    rbr6++;
                                    x = x + 1;
                                    sm = 1;
                                    counter--;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x + 1][y] = '*';
                                if (counter < 2)
                                {
                                    sm = 2; x = x - 1;
                                }
                                else
                                    sm = 0;
                                mjesto[0] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 2 && x > 1 && mjesto[1] == 0)
                    {
                        
                        if (rcheck[x - 1][y] == 0)
                        {
                            rcheck[x - 1][y] = 1;
                            if (player[x - 1][y] != 0)
                            {
                                switch (player[x - 1][y])
                                {
                                case 2:
                                    playervis[x - 1][y] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 3:
                                    playervis[x - 1][y] = 'X';
                                    rbr3++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 4:
                                    playervis[x - 1][y] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 5:
                                    playervis[x - 1][y] = 'X';
                                    rbr5++;
                                    sm++;
                                    mjesto[1] = 1;
                                    break;
                                case 6:
                                    playervis[x - 1][y] = 'X';
                                    rbr6++;
                                    counter--;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x - 1][y] = '*';
                                if (counter < 2)
                                {
                                    sm = 1; x = x + 1;
                                }
                                else
                                    sm = 0;
                                mjesto[1] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 3 && y < 10 && mjesto[2] == 0)
                    {
                        
                        if (rcheck[x][y + 1] == 0)
                        {
                            rcheck[x][y + 1] = 1;
                            if (player[x][y + 1] != 0)
                            {
                                switch (player[x][y + 1])
                                {
                                case 2:
                                    playervis[x][y + 1] = 'X';
                                    rbr2++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 3:
                                    playervis[x][y + 1] = 'X';
                                    rbr3++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 4:
                                    playervis[x][y + 1] = 'X';
                                    rbr4++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 5:
                                    playervis[x][y + 1] = 'X';
                                    rbr5++;
                                    sm++;
                                    mjesto[2] = 1;
                                    break;
                                case 6:
                                    playervis[x][y + 1] = 'X';
                                    rbr6++;
                                    sm++;
                                    counter--;
                                    y = y + 1;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y + 1] = '*';
                                if (counter < 2)
                                {
                                    sm = 4; y = y - 1;
                                }
                                else
                                    sm = 0;
                                mjesto[2] = 1;
                                k++;
                            }
                        }
                    }
                    else if (sm == 4 && y > 1 && mjesto[3] == 0)
                    {
                        mjesto[3] = 1;
                        if (rcheck[x][y - 1] == 0)
                        {
                            rcheck[x][y - 1] = 1;
                            if (player[x][y - 1] != 0)
                            {
                                switch (player[x][y - 1])
                                {
                                case 2:
                                    playervis[x][y - 1] = 'X';
                                    rbr2++;
                                    sm--;
                                    break;
                                case 3:
                                    playervis[x][y - 1] = 'X';
                                    rbr3++;
                                    sm--;
                                    break;
                                case 4:
                                    playervis[x][y - 1] = 'X';
                                    rbr4++;
                                    sm--;
                                    break;
                                case 5:
                                    playervis[x][y - 1] = 'X';
                                    rbr5++;
                                    sm--;
                                    break;
                                case 6:
                                    playervis[x][y - 1] = 'X';
                                    rbr6++;
                                    counter--;
                                    break;
                                }
                            }
                            else
                            {
                                playervis[x][y - 1] = '*';
                                if (counter < 2)
                                {
                                    sm = 3; y = y + 1;
                                }
                                else
                                    sm = 0;
                                k++;
                            }
                        }
                    }
                    else mjesto[sm - 1] = 1; break;
                

                }
            }*/


            Rpogodak.open("Rpogodak.bin", ios::binary | ios::out);
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 11; j++)
                    Rpogodak.write((char*)&rcheck[i][j], sizeof(1));
            Rpogodak.close();

            /*robotMemory.open("Memory.txt", ios::out);
            for (int i = 0; i < 4; i++)
                robotMemory << mjesto[i];
            robotMemory << counter;
            robotMemory.close();*/
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
                    cout << playervis[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;


        system("cls");
        if (rbrod <= 0)
        {
            cout << "Vi ste pobjedili :D";
            return 0;
        }
        if (brod <= 0)
        {
            cout << "Izgubili ste >:)";
            return 0;
        }
    }
}

