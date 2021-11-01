// Sarah Gilliland
// UVA 10194 - Football (aka Soccer)
// CMPS 4883 - Programming Techniques
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// Struct to create a team object with many attributes
struct Team
{
    int goalScored = 0, goalAgainst = 0, wins, losses, ties, games, points, rank;
    string name;
};

// function to rank the teams according to instructions
void rankTeams(map<string, Team> Teams, int numTeams)
{
    int *foo;
    int i = 0;
    string name1 = "", name2 = "";
    Team temp;

    // blank array to hold Team objects
    Team *ranking = new Team[numTeams];

    // go through map and put Team objects in an array
    for (auto it = Teams.cbegin(); it != Teams.cend(); ++it)
    {
        ranking[i] = it->second;
        i++;
    }

    for (i = 0; i < numTeams; i++)
    {
        for (int j = i + 1; j < numTeams; j++)
        {
            // rank by points
            if (ranking[i].points < ranking[j].points)
            {
                temp = ranking[i];
                ranking[i] = ranking[j];
                ranking[j] = temp;
            }
            // if a tie, rank by wins
            else if (ranking[i].points == ranking[j].points)
            {
                if (ranking[i].wins < ranking[j].wins)
                {
                    temp = ranking[i];
                    ranking[i] = ranking[j];
                    ranking[j] = temp;
                }
                // if a tie, rank by goalScored - goalAgainst
                else if (ranking[i].wins == ranking[j].wins)
                {
                    if ((ranking[i].goalScored - ranking[i].goalAgainst) <
                        (ranking[j].goalScored - ranking[j].goalAgainst))
                    {
                        temp = ranking[i];
                        ranking[i] = ranking[j];
                        ranking[j] = temp;
                    }
                    // if a tie, rank by goalScored
                    else if ((ranking[i].goalScored - ranking[i].goalAgainst) ==
                             (ranking[j].goalScored - ranking[j].goalAgainst))
                    {
                        if (ranking[i].goalScored < ranking[j].goalScored)
                        {
                            temp = ranking[i];
                            ranking[i] = ranking[j];
                            ranking[j] = temp;
                        }
                        // if a tie, rank by least games played
                        else if (ranking[i].goalScored == ranking[j].goalScored)
                        {
                            if (ranking[i].games > ranking[j].games)
                            {
                                temp = ranking[i];
                                ranking[i] = ranking[j];
                                ranking[j] = temp;
                            }
                            // if a tie, rank by lexicographical
                            else if (ranking[i].games == ranking[j].games)
                            {
                                // convert names to lowercase to compare them
                                for (int s = 0; s < ranking[i].name.length(); s++)
                                    name1 += tolower(ranking[i].name[s]);
                                for (int s = 0; s < ranking[j].name.length(); s++)
                                    name2 += tolower(ranking[j].name[s]);

                                // lexicographical order
                                if (name1 > name2)
                                {
                                    temp = ranking[i];
                                    ranking[i] = ranking[j];
                                    ranking[j] = temp;
                                }

                                // clear
                                name1 = "";
                                name2 = "";
                            }
                        }
                    }
                }
            }
        }
    }

    // print the results
    for (i = 0; i < numTeams; i++)
    {
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)",
               i + 1, ranking[i].name.c_str(), ranking[i].points, ranking[i].games,
               ranking[i].wins, ranking[i].ties, ranking[i].losses,
               ranking[i].goalScored - ranking[i].goalAgainst,
               ranking[i].goalScored, ranking[i].goalAgainst);
        cout << endl;
    }
}

int main()
{
    int numTournaments, numTeams, numMatches, goal1, goal2;
    string tournament, team1 = "", team2 = "";
    char l = ' ', extra; // used for parsing the string

    cin >> numTournaments;
    cin.ignore();
    for (int i = 0; i < numTournaments; i++)
    {
        map<string, Team> Teams;
        map<string, Team>::iterator it1;
        map<string, Team>::iterator it2;

        getline(cin, tournament);
        cin >> numTeams;
        cin.ignore();

        for (int j = 0; j < numTeams; j++)
        {
            Team newTeam;
            getline(cin, newTeam.name);
            Teams.insert({newTeam.name, newTeam});
        }

        cin >> numMatches;
        cin.ignore();

        for (int j = 0; j < numMatches; j++)
        {
            getline(cin, team1, '#');

            cin >> goal1; // read in their goals
            cin >> extra; // read in @ sign
            cin >> goal2; // read in the opponent's goals
            cin >> extra; // read in # sign

            // update goalcount for team1
            it1 = Teams.find(team1);
            it1->second.games++;
            it1->second.goalScored += goal1;
            it1->second.goalAgainst += goal2;

            getline(cin, team2);

            // update goalcount for team2
            it2 = Teams.find(team2);
            it2->second.games++;
            it2->second.goalScored += goal2;
            it2->second.goalAgainst += goal1;

            // do comarisons and points for each team
            if (goal1 > goal2)
            {
                it1->second.wins += 1;
                it1->second.points += 3; // winner earns 3 points
                it2->second.losses += 1;
            }
            else if (goal2 > goal1)
            {
                it2->second.wins += 1;
                it2->second.points += 3; // winner earns 3 points
                it1->second.losses += 1;
            }
            else
            {
                it2->second.ties += 1;
                it1->second.ties += 1;
                it1->second.points += 1; // tie earns 1 point
                it2->second.points += 1; // tie earns 1 point
            }
            team1 = "";
            team2 = "";
            l = ' ';
        }
        cout << tournament << endl;
        rankTeams(Teams, numTeams);
        if (i != numTournaments - 1)
            cout << endl;
    }
    return 0;
}