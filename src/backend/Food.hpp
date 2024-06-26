#include "../libs/nlohmann_json/json.hpp"


using json = nlohmann::json;
namespace JK
{
    struct Food
    {
        int id;
        int kcal;
        int gram;
        std::string type;
        std::string title;
    };

    /*void to_json(json& j, const Food& food) 
    {
        j = json{{"id", food.id}, {"kcal", food.kcal}, {"gram", food.gram}, {"type", food.type}, {"title", food.title}};
    }

    void from_json(const json& j, Food& food) 
    {
        j.at("id").get_to(food.id);
        j.at("kcal").get_to(food.kcal);
        j.at("gram").get_to(food.gram);
        j.at("type").get_to(food.type);
        j.at("title").get_to(food.title);
    }*/
}
