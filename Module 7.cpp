///Remain Code of module 7..
{

        char students[50][100] = {};
        char friends[50][5][100] = {};
        int studentCount = 0;

        char line[512];
        while (file.getline(line, sizeof(line)) && studentCount < 50)
        {
            std::stringstream ss(line);
            char name[100];
            int friendIndex = 0;

            while (ss.getline(name, sizeof(name), ',') && friendIndex < 6)
            {
                if (friendIndex == 0)
                    std::strcpy(students[studentCount], name);
                else
                    std::strcpy(friends[studentCount][friendIndex - 1], name);
                friendIndex++;
            }

            studentCount++;
        }
        file.close();

        int alpha = 3;
        std::string resultText;
        int directFriendCount[50] = {0};
        int commonFriendCount[50] = {0};

        for (int i = 0; i < studentCount; i++)
        {
            for (int j = i + 1; j < studentCount; j++)
            {
                bool areDirectFriends = false;
                for (int k = 0; k < 5; k++)
                {
                    if (std::strcmp(friends[i][k], students[j]) == 0)
                    {
                        areDirectFriends = true;
                        break;
                    }
                }

                if (areDirectFriends)
                {
                    directFriendCount[i]++;
                    directFriendCount[j]++;
                }
                else
                {
                    int commonCount = 0;
                    std::string commonList;

                    for (int k = 0; k < 5; k++)
                    {
                        for (int l = 0; l < 5; l++)
                        {
                            if (std::strcmp(friends[i][k], friends[j][l]) == 0 && std::strlen(friends[i][k]) > 0)
                            {
                                commonCount++;
                                if (!commonList.empty())
                                    commonList += ", ";
                                commonList += friends[i][k];
                            }
                        }
                    }

                    if (commonCount >= alpha)
                    {
                        resultText += "Potential friendship between ";
                        resultText += students[i];
                        resultText += " and ";
                        resultText += students[j];
                        resultText += " with common friends: ";
                        resultText += commonList;
                        resultText += " (";
                        resultText += std::to_string(commonCount);
                        resultText += " common friends)\n";

                        commonFriendCount[i] += commonCount;
                        commonFriendCount[j] += commonCount;
                    }
                }
            }
        }

        int maxDirectFriends = 0;
        int maxCommonFriends = 0;
        for (int i = 0; i < studentCount; i++)
        {
            if (directFriendCount[i] > maxDirectFriends)
                maxDirectFriends = directFriendCount[i];
            if (commonFriendCount[i] > maxCommonFriends)
                maxCommonFriends = commonFriendCount[i];
        }

        resultText += "\nBroadcast Points (Most Connected Students):\n";
        for (int i = 0; i < studentCount; i++)
        {
            if (directFriendCount[i] == maxDirectFriends)
            {
                resultText += students[i];
                resultText += " (Direct Friends: ";
                resultText += std::to_string(directFriendCount[i]);
                resultText += ")\n";
            }
            if (commonFriendCount[i] == maxCommonFriends)
            {
                resultText += students[i];
                resultText += " (Common Friends: ";
                resultText += std::to_string(commonFriendCount[i]);
                resultText += ")\n";
            }
        }

        if (resultText.empty())
        {
            resultText = "No potential friendships found.";
        }

        outputArea->setText(QString::fromStdString(resultText));
    });

    window.show();
    return app.exec();
}
