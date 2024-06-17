#include <iostream>
#include <tgbot/tgbot.h>
using namespace std;
using namespace TgBot;




















int main() {

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
    
    
    
    

    bot.getEvents().onCallbackQuery([&bot](CallbackQuery::Ptr query) {

        if (query->data == "HajimeruEasyK")
        {

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





