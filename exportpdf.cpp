#include "exportpdf.h"

exportPDF::exportPDF(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exportPDF)
{
    ui->setupUi(this);
    //connect(ui->pushButton_export, &QPushButton::clicked, this, &exportPDF::on_pushButton_export_clicked); not needed

}

void exportPDF::on_pushButton_export_clicked()
{
    //std::cout << "Generating pdf...";
    qDebug("Generating pdf...");
    PDFHandler pdf = PDFHandler(this, fp);
}

exportPDF::exportPDF(QWidget *parent, QString name, double weight, double height, double bodyfat, int age, QString comboBoxSomatotyp, QString RB_gender, QString RB_activity, QString RB_goal, QString RB_training, double LeanBodyMass, double BasalMetabolism, int Calories, int Protein, int Carbohydrates, int Fats) :
    QMainWindow(parent),
    ui(new Ui::exportPDF)
{
    ui->setupUi(this);

    //hodnoty přijaté od klienta
    ui->Line_Name->setText(name);
    ui->Line_Weight->setText(QString::number(weight));
    ui->Line_Height->setText(QString::number(height));
    ui->Line_Bodyfat->setText(QString::number(bodyfat));
    ui->Line_Age->setText(QString::number(age));
    ui->Line_Somatotyp->setText(comboBoxSomatotyp);
    ui->Line_Gender->setText(RB_gender);
    ui->Line_Activity->setText(RB_activity);
    ui->Line_Goal->setText(RB_goal);
    ui->Line_Training->setText(RB_training);


    // nastavení hodnot vypočitaných v form.cpp
    ui->Line_LBM->setText(QString::number(LeanBodyMass));
    ui->Line_BM->setText(QString::number(BasalMetabolism));
    ui->Line_Cal->setText(QString::number(Calories));
    ui->Line_Protein->setText(QString::number(Protein));
    ui->Line_Carb->setText(QString::number(Carbohydrates));
    ui->Line_Fats->setText(QString::number(Fats));

    //Wtf czech comments, bro, bro ... Anyways the following line is not needed4
    //Litierkdlay me
    //I am going insane, please end microsoft and it's products
    //Defender blocks qt apps, I hate it
    //Installing arch linux today, ngl
    //So i will use my beatiful class FitnessPerson so i don't mess with the bloody oblivious things my master did

    Somatotype st;
    if (comboBoxSomatotyp == "Ektomorph")
    {
        st = Somatotype::EKTOMORF;
    }
    else if (comboBoxSomatotyp == "Mezomorph")
    {
        st = Somatotype::MEZOMORF;
    }
    else if (comboBoxSomatotyp == "Endomorph")
    {
        st = Somatotype::ENDOMORF;
    }
    else if (comboBoxSomatotyp == "Ektomezomorph")
    {
        st = Somatotype::EKTOMEZOMORF;
    }
    else if (comboBoxSomatotyp == "Endomezomorph")
    {
        st = Somatotype::ENDOMEZOMORF;
    }
    Gender g;
    //Gender
    if (RB_gender == "Male")
    {
        g = Gender::Male;
    }
    else
    {
        g = Gender::Female;
    }
    //Activity
    Activity a;
    if (RB_activity == "Light activity")
    {
        a = Activity::ACTIVITY_LIGHT;
    }
    else if (RB_activity == "Medium activity")
    {
        a = Activity::ACTIVITY_MIDDLE;
    }
    else if (RB_activity == "Intensive activity")
    {
        a = Activity::ACTIVITY_INTENSIVE;
    }
    else
    {
        a = Activity::ACTIVITY_NO;
    }
    Goal goal;
    if (RB_goal == "Lose weight")
    {
        goal = Goal::WEIGHT_LOOSE;
    }
    else if (RB_goal == "Weight maintenaince")
    {
        goal = Goal::WEIGHT_MAINTENANCE;
    }
    else if (RB_goal == "Gain weight")
    {
        goal = Goal::WEIGHT_GAIN;
    }
    fp = FitnessPerson(age, height, weight, bodyfat, st, a, goal, name.toStdString(), g, false);
    fp.Fats = Fats;
    fp.Protein = Protein;
    fp.Carbohydrates = Carbohydrates;
    fp.LBM = LeanBodyMass;
    fp.BM = BasalMetabolism;
    fp.Calories = Calories;

    qDebug("Fitness person created, data:");
    std::cout << fp.name << std::endl;
    std::cout << fp.height << std::endl;
    std::cout << fp.weight << std::endl;
    std::cout << fp.body_fat << std::endl;
    std::cout << fp.age << std::endl;
    std::cout << fp.somaToString.at(fp.soma_type) << std::endl;
    std::cout << fp.activityToString.at(fp.activity) << std::endl;
    std::cout << fp.goalToString.at(fp.target_goal) << std::endl;
    std::cout << fp.genderToString.at(fp.gender) << std::endl;
    std::cout << "Cals: " << fp.Calories << std::endl;
    std::cout << "Protein: " << fp.Protein << std::endl;
    std::cout << "Carbs: " << fp.Carbohydrates << std::endl;
    std::cout << "Fats: " << fp.Fats << std::endl;
    std::cout << "LBM: " << fp.LBM << std::endl;

}

exportPDF::~exportPDF()
{
    delete ui;
}
