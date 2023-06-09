#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool check1(int x, int y, int smjer, int ch)
{
    switch (ch)
    {
    case 2:
        if ((x < 10 && smjer != 2) || (y < 10 && smjer != 1))
            return 1; break;
    case 3:
        if ((x < 9 && smjer != 2) || (y < 9 && smjer != 1)) return 1;             break;
    case 4:
        if ((x < 8 && smjer != 2) || (y < 8 && smjer != 1)) return 1;
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
    int pk, pkr, hit = 0, smjer;  //smjer -> 1 (okomito) , 2 (vodoravno)

    char robovis[12][12];
    char playervis[12][12] = { 0 };

    // 4(*1),3/6(*2),2/5(*2) brodovi
    srand(time(0));

    //datoteke
    fstream playerBrod;
    fstream robotBrod;
    fstream Ppogodak;
    fstream Rpogodak;
    fstream Ppotopljeno;  //BINARNO
    fstream Rpotopljeno;  //BINARNO


    cout << "Imena brodova su 4(zauzima 4 polja), 3(zauzima 3 polja), 2(zauzima 2 polje), dva puta     birate brodove 3 i 2." << endl;

    cout << "Brod mozete postaviti okomito (1) i vodoravno (2)" << endl << endl;

    //robot visual setup
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            robovis[i][j] = '0';
    //start menu
    cout << "Sto zelite napraviti?\n\n\n" << "Start new game(0)" << endl << "Continue game(1)" << endl << "Exit(2)" << endl;
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
        Ppogodak.open("Ppogodak.txt", ios::in);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                Ppogodak >> check[i][j];
        Ppogodak.close();
        Rpogodak.open("Rpogodak.txt", ios::in);
        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                Rpogodak >> rcheck[i][j];
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
    }


    if (option == 1)
    {
        Rpotopljeno.open("Rpotopljeno.txt", ios::in);
        Ppotopljeno.open("Ppotopljeno.txt", ios::in);
        Ppotopljeno >> br2;
        Ppotopljeno >> br3;
        Ppotopljeno >> br4;
        Ppotopljeno >> br5;
        Ppotopljeno >> br6;
        Rpotopljeno >> rbr2;
        Rpotopljeno >> rbr3;
        Rpotopljeno >> rbr4;
        Rpotopljeno.close();
        Ppotopljeno.close();
    }


    //pocetni screen
    system("cls");





    //game
    while ((rbrod > 0) || (brod > 0)) {

        //player turn
        for (int i = 0; i == 0;)
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
                            cout << "Brod 2 je potopljen" << endl;
                            br2++;
                            rbrod--;
                        }
                        system("cls");
                        break;
                    case 3:
                        robovis[x][y] = 'X';
                        br3++;
                        if (br3 == 3)
                        {
                            cout << "Brod 3 je potopljen" << endl;
                            br3++;
                            rbrod--;
                        }
                        system("cls");
                        break;
                    case 4:
                        robovis[x][y] = 'X';
                        br4++;
                        if (br4 == 4)
                        {
                            br4++;
                            cout << "Brod 4 je potopljen" << endl;
                            rbrod--;
                        }
                        system("cls");
                        break;
                    case 5:
                        robovis[x][y] = 'X';
                        br5++;
                        if (br5 == 2)
                        {
                            br5++;
                            cout << "Brod 2 je potopljen" << endl;
                            rbrod--;
                        }
                        system("cls");
                        break;
                    case 6:
                        robovis[x][y] = 'X';
                        br6++;
                        if (br6 == 3)
                        {
                            cout << "Brod 3 je potopljen" << endl;
                            br6++;
                            rbrod--;
                        }
                        system("cls");
                        break;
                    }
                }
                else
                {
                    robovis[x][y] = '*';
                    i++;
                    system("cls");
                }

            }
            else
            {
                system("cls");
                cout << endl << endl << "vec ste tu pogodili." << endl << endl << endl;

            }

            Ppogodak.open("Ppogodak.txt", ios::out);
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 11; j++)
                    Ppogodak << check[x][y] << " ";
            Ppogodak.close();

            Ppotopljeno.open("Ppotopljeno.txt", ios::out);
            Ppotopljeno << br2;
            Ppotopljeno << " ";
            Ppotopljeno << br3;
            Ppotopljeno << " ";
            Ppotopljeno << br4;
            Ppotopljeno << " ";
            Ppotopljeno << br5;
            Ppotopljeno << " ";
            Ppotopljeno << br6;
            Ppotopljeno.close();
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
            Rpogodak.open("Rpogodak.txt", ios::out);
            for (int i = 0; i < 11; i++)
                for (int j = 0; j < 11; j++)
                    Rpogodak << rcheck[i][j];
            Rpogodak.close();
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

