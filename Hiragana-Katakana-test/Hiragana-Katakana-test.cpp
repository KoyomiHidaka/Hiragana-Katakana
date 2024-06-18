#include <iostream>
#include <tgbot/tgbot.h>
#include <map>
#include <random>
#include <ctime>
#include <stdlib.h>
#include<cstdlib>
#include <set>
using namespace std;
using namespace TgBot;
#pragma execution_character_set("utf-8")





map<int, string> EasyK{

    {1, "a"},
    {2, "i"},
    {3, "u"},
    {4, "e"},
    {5, "o"},
    {6, "ka"},
    {7, "ki"},
    {8, "ku"},
    {9, "ke"},
    {10, "ko"},
    {11, "sa"},
    {12, "si"},
    {13, "su"},
    {14, "se"},
    {15, "so"},
    {16, "ta"},
    {17, "chi"},
    {18, "tsu"},
    {19, "te"},
    {20, "to"}
};


map<int, string> EasyK_Glyph{

    {1, "ア"},
    {2, "イ"},
    {3, "ウ"},
    {4, "エ"},
    {5, "オ"},
    {6, "カ"},
    {7, "キ"},
    {8, "ク"},
    {9, "ケ"},
    {10, "コ"},
    {11, "サ"},
    {12, "si"},
    {13, "ス"},
    {14, "セ"},
    {15, "ソ"},
    {16, "タ"},
    {17, "チ"},
    {18, "ツ"},
    {19, "テ"},
    {20, "ト"}
};



vector<int> keys;
size_t currentIndex = 0;



void initializeKeys() {
    for (const auto& pair : EasyK_Glyph) {
        keys.push_back(pair.first);
    }
    random_device rd;
    mt19937 gen(rd());
    shuffle(keys.begin(), keys.end(), gen);

}





































int main() {
    initializeKeys();
    Bot bot("7170257322:AAHG4-WJYFGR8_C43O8ChijxrBB-DEWvGN8");



    bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
        bot.getApi().sendMessage(message->chat->id, "Hello!");

        InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);

        //Create Button

        InlineKeyboardButton::Ptr button1(new InlineKeyboardButton);
        button1->text = "Katakana";
        button1->callbackData = "Katakana";
        InlineKeyboardButton::Ptr button2(new InlineKeyboardButton);
        button2->text = "Hiragana";
        button2->callbackData = "Hiragana";






        //Create structure

        vector <InlineKeyboardButton::Ptr> row;

        //Add Buttons to structure

        row.push_back(button1);
        row.push_back(button2);

        //Add Keyboard with buttons

        keyboard->inlineKeyboard.push_back(row);



        bot.getApi().sendMessage(message->chat->id, "Select mode",false, 0, keyboard);
        });





    bot.getEvents().onCallbackQuery([&bot](CallbackQuery::Ptr query) {

        if (query->data == "Katakana")
        {
            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);


            InlineKeyboardButton::Ptr button1(new InlineKeyboardButton);
            InlineKeyboardButton::Ptr button2(new InlineKeyboardButton);

            button1->text = "Katakana/Easy(1-20)";
            button1->callbackData = "EasyK";
            button2->text = "Katakana/Hard(20-44)";
            button2->callbackData = "HardK";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(button1);
            row.push_back(button2);

            keyboard->inlineKeyboard.push_back(row);

            bot.getApi().sendMessage(query->message->chat->id, "Select difficult", false, 0, keyboard);


        }

        if (query->data == "Hiragana")
        {
            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);


            InlineKeyboardButton::Ptr button1(new InlineKeyboardButton);
            InlineKeyboardButton::Ptr button2(new InlineKeyboardButton);

            button1->text = "Hiragana/Easy(1-20)";
            button1->callbackData = "EasyH";
            button2->text = "Hiragana/Hard(20-44)";
            button2->callbackData = "HardH";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(button1);
            row.push_back(button2);

            keyboard->inlineKeyboard.push_back(row);

            bot.getApi().sendMessage(query->message->chat->id, "Select difficult", false, 0, keyboard);

            
        }
        });
    
    bot.getEvents().onCallbackQuery([&bot](CallbackQuery::Ptr query) {


        if (query->data == "EasyK")
        {

            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
            InlineKeyboardButton::Ptr hajimeru(new InlineKeyboardButton);
            
            hajimeru->text = "Hajimeru!";
            hajimeru->callbackData = "HajimeruEasyK";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(hajimeru);
            keyboard->inlineKeyboard.push_back(row);

            bot.getApi().sendMessage(query->message->chat->id, "Hajimeru!", false, 0, keyboard);
        }
        if (query->data == "HardK")
        {

            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
            InlineKeyboardButton::Ptr hajimeru(new InlineKeyboardButton);

            hajimeru->text = "Hajimeru!";
            hajimeru->callbackData = "HajimeruHardK";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(hajimeru);
            keyboard->inlineKeyboard.push_back(row);


            bot.getApi().sendMessage(query->message->chat->id, "Hajimeru!", false, 0, keyboard);
        }
        if (query->data == "EasyH")
        {

            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
            InlineKeyboardButton::Ptr hajimeru(new InlineKeyboardButton);

            hajimeru->text = "Hajimeru!";
            hajimeru->callbackData = "HajimeruEasyH";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(hajimeru);
            keyboard->inlineKeyboard.push_back(row);

            bot.getApi().sendMessage(query->message->chat->id, "Hajimeru!", false, 0, keyboard);
        }
        if (query->data == "HardH")
        {

            InlineKeyboardMarkup::Ptr keyboard(new InlineKeyboardMarkup);
            InlineKeyboardButton::Ptr hajimeru(new InlineKeyboardButton);

            hajimeru->text = "Hajimeru!";
            hajimeru->callbackData = "HajimeruHardH";
            vector<InlineKeyboardButton::Ptr> row;
            row.push_back(hajimeru);
            keyboard->inlineKeyboard.push_back(row);

            bot.getApi().sendMessage(query->message->chat->id, "Hajimeru!", false, 0, keyboard);
        }
        });
    
    
    //string selectedQuestionableGlyph;
    string selectedAnswerforGlyph;
    int counter_wrong;
    int counter_right;
 

    bot.getEvents().onCallbackQuery([&bot, &selectedAnswerforGlyph](CallbackQuery::Ptr query) {

        if (query->data == "HajimeruEasyK")
        {
            if (currentIndex < keys.size())
            {
                int randomKeyfromVector = keys[currentIndex];
                string selectedQuestionableGlyph = EasyK_Glyph[randomKeyfromVector]; // glyph To
                string selectedAnswerforGlyph = EasyK[randomKeyfromVector];  // To 

                InlineKeyboardMarkup::Ptr EasyK_kb(new InlineKeyboardMarkup);
                InlineKeyboardButton::Ptr option1(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr option2(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr option3(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr option4(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr option5(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr divider(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr help(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr next(new InlineKeyboardButton);
                InlineKeyboardButton::Ptr finish(new InlineKeyboardButton);


                //random_device rd;
                //mt19937 gen(rd());
                //uniform_int_distribution<> dis1(1, 5);
                //uniform_int_distribution<> dis2(1, 20);
                //int randomPos = dis1(gen);
                //int randomoption2 = dis2(gen);
                //int randomoption3 = dis2(gen);
                //int randomoption4 = dis2(gen);
                //int randomoption5 = dis2(gen);
                //string option2text = EasyK[randomoption2 - 1];
                //string option3text = EasyK[randomoption3 - 1];
                //string option4text = EasyK[randomoption4 - 1];
                //string option5text = EasyK[randomoption5 - 1];

                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis1(1, 5);
                uniform_int_distribution<> dis2(1, 20);
                int randomPos = dis1(gen);
                set<int> uniqueOptions;
                uniqueOptions.insert(dis2(gen));

                while (uniqueOptions.size() < 4) {
                    uniqueOptions.insert(dis2(gen));
                }

                auto it = uniqueOptions.begin();
                int randomoption2 = *it++;
                int randomoption3 = *it++;
                int randomoption4 = *it++;
                int randomoption5 = *it++;

                string option2text = EasyK[randomoption2 - 1];
                string option3text = EasyK[randomoption3 - 1];
                string option4text = EasyK[randomoption4 - 1];
                string option5text = EasyK[randomoption5 - 1];



                switch (randomPos)
                {
                    case 1:
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 2:  
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 3:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 4:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 5:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                }
                bot.getApi().sendMessage(query->message->chat->id, selectedQuestionableGlyph, false, 0, EasyK_kb);
                ++currentIndex;

            }
            else
            {
                bot.getApi().sendMessage(query->message->chat->id, "Тест завершен результат: "); //добавить скольок из скольки было верно отвечено
            }
        }
        if (query->data == "HajimeruHardK")
        {
           
        }
        if (query->data == "HajimeruEasyH")
        {
            
        }
        if (query->data == "HajimeruHardH")
        {
            
        }
        });





        bot.getEvents().onCallbackQuery([&bot, &selectedAnswerforGlyph, &counter_right, &counter_wrong](CallbackQuery::Ptr query) {


            if (query->data == "RightAnswer")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Correct");
                counter_right+=1;
            }
            if ((query->data == "WrongAnswer02") || (query->data == "WrongAnswer03") || (query->data == "WrongAnswer04") || (query->data == "WrongAnswer05"))
            {
                bot.getApi().sendMessage(query->message->chat->id, "Incorrect");
                counter_wrong+=1;

            }
            if (query->data == "nextQuestion")
            {

            }
            if (query->data == "helpWithTest")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Правильный ответ был: " + selectedAnswerforGlyph);
                counter_wrong+=1;
            }
            if (query->data == "completethetest")
            {
                bot.getApi().sendMessage(query->message->chat->id, "Количество набранных баллов: " + counter_right);
            }
            });

















        bot.getEvents().onCallbackQuery([&bot](CallbackQuery::Ptr query) {

            if ((query->data == "nextQuestion") || (query->data == "RightAnswer") || (query->data == "WrongAnswer02") || (query->data == "WrongAnswer03") || (query->data == "WrongAnswer04") || (query->data == "WrongAnswer05"))
            {
                if (currentIndex < keys.size())
                {
                    int randomKeyfromVector = keys[currentIndex];
                    string selectedQuestionableGlyph = EasyK_Glyph[randomKeyfromVector]; // glyph To
                    string selectedAnswerforGlyph = EasyK[randomKeyfromVector];  // To 

                    InlineKeyboardMarkup::Ptr EasyK_kb(new InlineKeyboardMarkup);
                    InlineKeyboardButton::Ptr option1(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr option2(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr option3(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr option4(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr option5(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr divider(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr help(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr next(new InlineKeyboardButton);
                    InlineKeyboardButton::Ptr finish(new InlineKeyboardButton);


                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dis1(1, 5);
                    uniform_int_distribution<> dis2(1, 20);
                    int randomPos = dis1(gen);
                    int randomoption2 = dis2(gen);
                    int randomoption3 = dis2(gen);
                    int randomoption4 = dis2(gen);
                    int randomoption5 = dis2(gen);
                    string option2text = EasyK[randomoption2];
                    string option3text = EasyK[randomoption3];
                    string option4text = EasyK[randomoption4];
                    string option5text = EasyK[randomoption5];

                    switch (randomPos)
                    {
                    case 1:
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 2:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 3:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 4:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    case 5:
                        option2->text = option2text;
                        option2->callbackData = "WrongAnswer02";
                        EasyK_kb->inlineKeyboard.push_back({ option2 });
                        option3->text = option3text;
                        option3->callbackData = "WrongAnswer03";
                        EasyK_kb->inlineKeyboard.push_back({ option3 });
                        option4->text = option4text;
                        option4->callbackData = "WrongAnswer04";
                        EasyK_kb->inlineKeyboard.push_back({ option4 });
                        option5->text = option5text;
                        option5->callbackData = "WrongAnswer05";
                        EasyK_kb->inlineKeyboard.push_back({ option5 });
                        option1->text = selectedAnswerforGlyph;
                        option1->callbackData = "RightAnswer";
                        EasyK_kb->inlineKeyboard.push_back({ option1 });
                        divider->text = "-------------------";
                        divider->callbackData = "------------------";
                        EasyK_kb->inlineKeyboard.push_back({ divider });
                        help->text = "Click if you don`t know";
                        help->callbackData = "helpWithTest";
                        EasyK_kb->inlineKeyboard.push_back({ help });
                        next->text = "Next";
                        next->callbackData = "nextQuestion";
                        EasyK_kb->inlineKeyboard.push_back({ next });
                        finish->text = "Complete The Test";
                        finish->callbackData = "completethetest";
                        EasyK_kb->inlineKeyboard.push_back({ finish });
                        break;
                    }
                    bot.getApi().sendMessage(query->message->chat->id, selectedQuestionableGlyph, false, 0, EasyK_kb);
                    ++currentIndex;

                }
            }
            });
        

            
        
        
        
        
        
        















































































    try {
        TgLongPoll longPoll(bot);
        while (true) {
            cout << "Long poll started^^" << endl;
            longPoll.start();
        }
    }
    catch (TgException& e) {
        cout << "error: " << e.what() << endl;
    }



	return 0;


}





