#include <string>
#include <bits/stdc++.h> 
enum Gender
{
    Male,
    Female
};  

enum Somatotype
{
    EKTOMORF=1,
    EKTOMEZOMORF=2,
    MEZOMORF=3,
    ENDOMEZOMORF=4,
    ENDOMORF=5
};

enum Goal
{
    WEIGHT_LOOSE=1,
    WEIGHT_MAINTENANCE=2,
    WEIGHT_GAIN=3
};
enum Activity
{
    ACTIVITY_NO=1,
    ACTIVITY_LIGHT=2,
    ACTIVITY_MIDDLE=3,
    ACTIVITY_INTENSIVE=4
};
//Class that holds Person nutritional values and calculates them
class FitnessPerson
{
    private:
        void calculateSomaCoeficent();
        void calculateActivityCoeficent();
        void calculateGoalCoeficient();
        void calculateLeanBodyMassCoeficient();
        void calculateBasalMetabolismCoeficient();
        void calculateNutrientsCoeficients();
        void scaleNutrients();
        //Number-like variables
        double soma, activ, G;
        double A, B, C; //Mysterious variables
        //Even more magic vars
        
        double CarbF, Ca;

        //Scaling coeficients
        const double breakfastCoeficients[4] = {0.35, 0.2, 0.3, 0.3};
        const double lunchCoeficients[4] = {0.25, 0.25, 0.25, 0.25};
        const double snackCoeficients[4] = {0.2, 0.25, 0.2, 0.25};
        const double dinnerCoeficients[4] = {0.2, 0.3, 0.25, 0.2};

    public:
        //Numberish variables
        int age; //Age in years
        int height; //Height in cm
        Activity activity;
        double weight, body_fat;
        double LBM, BM; //Lean body mass and basal metabolism
        double Calories;
        double Protein;
        double Carbohydrates;
        double Fats;
        double P;
        double F;

        //Scaling output shall be stored here, in the order {calories, protein, carbs, fats} - no will to implement std::map or sthg fancier, maybe a TODO for Mr. Church?
        double breakfastNutrients[4];
        double lunchNutrients[4];
        double snackNutrients[4];
        double dinnerNutrients[4];

        //Non number-like variables 
        Gender gender;
        Goal target_goal;
        Somatotype soma_type;
        std::string name;

        //Map for converting enums to string which are their name
        const std::map<Gender, std::string> genderToString = { {Gender::Male, "Muž"}, {Gender::Female, "Žena"}};
        const std::map<Somatotype, std::string> somaToString = { {Somatotype::EKTOMORF, "Ektomorf"}, {Somatotype::EKTOMEZOMORF, "Ektomezomorf"}, {Somatotype::MEZOMORF, "Mezomorf"}, {Somatotype::ENDOMEZOMORF, "Endomezomorf"}, {Somatotype::ENDOMORF, "Endomorf"}};
        const std::map<Goal, std::string> goalToString = { {Goal::WEIGHT_LOOSE, "Zhubnout"}, {Goal::WEIGHT_MAINTENANCE, "Udržet váhu"}, {Goal::WEIGHT_GAIN, "Přibrat"}};
        const std::map<Activity, std::string> activityToString = { {Activity::ACTIVITY_NO, "Žádná aktivita"}, {Activity::ACTIVITY_LIGHT, "Lehká aktivita"}, {Activity::ACTIVITY_MIDDLE, "Střední aktivita"}, {Activity::ACTIVITY_INTENSIVE, "Intenzivní aktivita"}};


        FitnessPerson(int age, int height, 
            double weight, double body_fat, 
            Somatotype soma_type, Activity activity,
            Goal target_goal, std::string name,
            Gender gender, bool calc = false);
        FitnessPerson();
        //Copy assignment operator - C++ wtf moment can't be outside header, end my suffering please
        FitnessPerson& operator=(const FitnessPerson& other)
        {
            if (this != &other)
            {
                this->age = other.age;
                this->height = other.height;
                this->weight = other.weight;
                this->body_fat = other.body_fat;
                this->soma_type = other.soma_type;
                this->activity = other.activity;
                this->target_goal = other.target_goal;
                this->name = other.name;
                //Calculate values
                calculateSomaCoeficent();
                calculateActivityCoeficent();
                calculateGoalCoeficient();
                calculateLeanBodyMassCoeficient();
                calculateBasalMetabolismCoeficient();
                calculateNutrientsCoeficients();
                scaleNutrients();
            }
            return *this;
        }

};



