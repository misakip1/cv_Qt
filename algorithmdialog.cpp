#include "algorithmdialog.h"
#include "ui_algorithmdialog.h"

AlgorithmDialog::AlgorithmDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AlgorithmDialog)
{
    ui->setupUi(this);
    config_=std::make_shared<AlgorithmConfig>();
    setWindowTitle("选择检测方案");

}

AlgorithmDialog::~AlgorithmDialog()
{
    qDebug()<<"配置界面析构";
    delete ui;
}

void AlgorithmDialog::on_buttonBox_accepted()
{
    config_->deformation = ui->deformation->isChecked();
    config_->broken = ui->broken->isChecked();
    config_->scuff = ui->scuff->isChecked();
    config_->whitePoint = ui->whitePoint->isChecked();
    config_->colorDifference = ui->colorDifference->isChecked();
    config_->grindingMark = ui->grindingMark->isChecked();
    config_->primerReturn = ui->primerReturn->isChecked();
    config_->exposedBase = ui->exposedBase->isChecked();
    config_->hangerMark = ui->hangerMark->isChecked();
    config_->dent = ui->dent->isChecked();
    config_->scratch = ui->scratch->isChecked();
    config_->crater = ui->crater->isChecked();
    config_->orangePeel = ui->orangePeel->isChecked();
    config_->aluminumChip = ui->aluminumChip->isChecked();
    config_->sprayFlow = ui->sprayFlow->isChecked();
    config_->bubble = ui->bubble->isChecked();
    config_->pit = ui->pit->isChecked();
    config_->coarseTexture = ui->coarseTexture->isChecked();
    config_->coatingCrack = ui->coatingCrack->isChecked();
    config_->dirt = ui->dirt->isChecked();
    config_->adhesion = ui->adhesion->isChecked();
    config_->powderBump = ui->powderBump->isChecked();
    config_->coatingScratch = ui->coatingScratch->isChecked();
    config_->pushDamage = ui->pushDamage->isChecked();
    config_->oil = ui->oil->isChecked();
    emit configMsg(config_);

}

