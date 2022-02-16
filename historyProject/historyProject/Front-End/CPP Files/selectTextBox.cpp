//#include "../Header Files/selectTextBox.h"
//
//void selectTextBox(sf::Event& userEvent, SELECTED_TEXT_BOX& textBoxFlag)
//{
//    switch (userEvent.type)
//    {
//    case sf::Event::TextEntered:
//        if (userEvent.text.unicode < 128 && textBoxFlag.titleTextBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForTitleBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForTitleBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForTitleBox.pop_back();
//                textBoxProperties::titleBox.setString(textBoxProperties::enteredTextForTitleBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.dateTextBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForDateBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDateBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForDateBox.pop_back();
//                textBoxProperties::dateBox.setString(textBoxProperties::enteredTextForDateBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.descriptionTextBox == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForDescriptionBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForDescriptionBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForDescriptionBox.pop_back();
//                textBoxProperties::descriptionBox.setString(textBoxProperties::enteredTextForDescriptionBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.username == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForUsernameBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForUsernameBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForUsernameBox.pop_back();
//                textBoxProperties::username.setString(textBoxProperties::enteredTextForUsernameBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.password == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForPasswordBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForPasswordBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForPasswordBox.pop_back();
//                textBoxProperties::password.setString(textBoxProperties::enteredTextForPasswordBox);
//            }
//        }
//        else if (userEvent.text.unicode < 128 && textBoxFlag.search == true)
//        {
//            if (userEvent.text.unicode != 13 && userEvent.text.unicode != 8)
//            {
//                textBoxProperties::enteredTextForSearchBox += static_cast<char>(userEvent.text.unicode);
//                textBoxProperties::search.setString(textBoxProperties::enteredTextForSearchBox);
//            }
//            else if (userEvent.text.unicode == 8 && textBoxProperties::enteredTextForSearchBox.size() > 0)
//            {
//                textBoxProperties::enteredTextForSearchBox.pop_back();
//                textBoxProperties::search.setString(textBoxProperties::enteredTextForSearchBox);
//            }
//        }
//
//        break;
//    default:
//        break;
//    }
//}