#include "Food.hpp"
#include <fstream>
#include <vector>
#include <iostream>

using json = nlohmann::json;
using namespace JK;

class FoodMenu
{
    public:
        //3D Vector array of the entire FoodMenu=jídelníček 
        std::vector<std::vector<std::vector<Food>>> dayMenuList; //Celý jídelníček
    
        void loadData(std::string json_file_path) // for future use - MOVE TO different class 
        {
            
            //Test if file exists, if not throw Exception
            if (FILE *file = fopen(json_file_path.c_str(), "r")) 
            {
                fclose(file);
                //continue with the program
            }
            else
            {
                //TODO: Implement exception
                //throw FileNotFoundException
            }

            //Load da data                        
            
            //Load json jidelnicek config into a stream
            std::ifstream f(json_file_path);
            //Parsing json
            json foodMenuJson = json::parse(f);    
            json foodMenu = foodMenuJson.at("jidelnicek"); //Here we get the jidelnicek object from json config
            //For loop that goes through every jidelnicek day

            // For loop that goes through every jidelnicek day
            for (auto dayMenuListIterator : foodMenu.items())
            {
                std::vector<std::vector<Food>> dayMenu; // Stores menu of one day
                std::vector<Food> breakfast;
                std::vector<Food> lunch;
                std::vector<Food> snack;
                std::vector<Food> dinner;

                // Go through all food included in snidane json list and load them in a vector
                for (const auto& foodIterator : dayMenuListIterator.value().at("snidane"))
                {
                    try
                    {
                        Food food = {foodIterator.at("id"), foodIterator.at("kcal"), foodIterator.at("gram"), foodIterator.at("type"), foodIterator.at("title")};
                        breakfast.push_back(food);
                    }
                    catch (const json::out_of_range& e)
                    {
                        std::cerr << "Debug: Missing key in snidane - " << e.what() << std::endl;
                        std::cerr << "Debug: Food item - " << foodIterator.dump() << std::endl;
                    }
                }

                // Go through all food included in obed json list and load them in a vector
                for (const auto& foodIterator : dayMenuListIterator.value().at("obed"))
                {
                    try
                    {
                        Food food = {foodIterator.at("id"), foodIterator.at("kcal"), foodIterator.at("gram"), foodIterator.at("type"), foodIterator.at("title")};
                        lunch.push_back(food);
                    }
                    catch (const json::out_of_range& e)
                    {
                        std::cerr << "Debug: Missing key in obed - " << e.what() << std::endl;
                        std::cerr << "Debug: Food item - " << foodIterator.dump() << std::endl;
                    }
                }

                // Go through all food included in snack json list and load them in a vector
                for (const auto& foodIterator : dayMenuListIterator.value().at("svacina"))
                {
                    try
                    {
                        Food food = {foodIterator.at("id"), foodIterator.at("kcal"), foodIterator.at("gram"), foodIterator.at("type"), foodIterator.at("title")};
                        snack.push_back(food);
                    }
                    catch (const json::out_of_range& e)
                    {
                        std::cerr << "Debug: Missing key in svacina - " << e.what() << std::endl;
                        std::cerr << "Debug: Food item - " << foodIterator.dump() << std::endl;
                    }
                }

                // Go through all food included in vecere json list and load them in a vector
                for (const auto& foodIterator : dayMenuListIterator.value().at("vecere"))
                {
                    try
                    {
                        Food food = {foodIterator.at("id"), foodIterator.at("kcal"), foodIterator.at("gram"), foodIterator.at("type"), foodIterator.at("title")};
                        dinner.push_back(food);
                    }
                    catch (const json::out_of_range& e)
                    {
                        std::cerr << "Debug: Missing key in vecere - " << e.what() << std::endl;
                        std::cerr << "Debug: Food item - " << foodIterator.dump() << std::endl;
                    }
                }

                // Load day meals to vector dayMenu - the order is important !!!!
                dayMenu.push_back(breakfast);
                dayMenu.push_back(lunch);
                dayMenu.push_back(snack);
                dayMenu.push_back(dinner);

                // Load the dayMenu into a vector that holds different days
                dayMenuList.push_back(dayMenu);
            }
        }


};
