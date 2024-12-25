 int alpha = 3;

    for (int i = 0; i < studentCount; i++)
    {
        for (int j = i + 1; j < studentCount; j++)
        {
            bool areDirectFriends = false;
            for (int k = 0; k < 5; k++)
            {
                if (friends[i][k] == students[j])
                {
                    areDirectFriends = true;
                    break;
                }
            }

            if (!areDirectFriends)
            {
                int commonCount = 0;
                string commonList = "";

                for (int k = 0; k < 5; k++)
                {
                    for (int l = 0; l < 5; l++)
                    {
                        if (friends[i][k] == friends[j][l] && !friends[i][k].empty())
                        {
                            commonCount++;
                            commonList += friends[i][k] + ", ";
                        }
                    }
                }

                if (commonCount >= alpha)
                {
                    if (!commonList.empty())
                        commonList = commonList.substr(0, commonList.length() - 2);

                    cout << "Potential friendship between " << students[i] << " and " << students[j]
                         << " with common friends: " << commonList << " (" << commonCount << " common friends)" << endl;
                }
            }
        }
    }
return 0;
}
