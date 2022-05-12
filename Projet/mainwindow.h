#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QScrollArea>
#include <QComboBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QFile>
#include <QFileInfo>
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QCheckBox>
#include <QCalendarWidget>
#include <QString>
#include <QStringList>
#include <QTextEdit>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextBlock>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>

#include "gestioncontact.h"
#include "database.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    const int taille = 1000;
    int indice, nbContact;

    GestionContact gestC;
    DataBase datas;
    QWidget * mainWidget;
    QWidget * contactPageWidget;
    QWidget * allContactPageWidget;


    QString fichier;
    QLabel * c_photo;
    QLineEdit * c_nom;
    QLineEdit * c_prenom;
    QLineEdit * c_entreprise;
    QLineEdit * c_numero;
    QLineEdit * c_email;

//=================================
    QPushButton * b_from;
    QPushButton * b_to;
    QPushButton * boom;

    QCalendarWidget * calendar_from;
    QCalendarWidget * calendar_to;

    std::list<Todo> listTodoModified;
    std::list<Interaction> listInteractionModified;
    Contact contactModified;

    QTextEdit* forAddInteraction;

    QCheckBox * cb_nom;
    QCheckBox * cb_prenom;
    QCheckBox * cb_entreprise;

    QLineEdit * search;
    int selection = 0;
    std::list<Contact> searchResult;

    void adapterPhoto();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void errorHappened(const QString&);
    void warningHappened(const QString&);
    void infoReceived(const QString&);
    void refresh();
    void showContact();
    void Quitter();

    void createMainWidget();
    QWidget* createContactForMainWidget(const Contact&);
    QWidget* createTodoForMainWidget(const Todo&);

    void createContactPageWidget();
    QWidget* createInteractionWidgetForContactPage(const Interaction&);
    QWidget* createTodoWidgetForContactPage(const Todo&);

    void insertContactPic();
    void ajoutContact();
    void verifier();
    void resetContact();
    void saveContact(const Contact&);
    void deleteContact(const QString&);

    void modificationContact();
    QWidget* createInteractionForModificationContact(const Interaction&);
    void deleteThisInteraction();
    void deleteThisTodo();
    void todoContenuModified();
    void todoDateModified();
    void interactionContenuModified();
    void interactionDateModified();
    void contactIsModified();
    void saveModification();

    void seeAllContacts();
    void createAllContactPageWidget();
    QWidget* createContactForAllContactPage(const Contact&);
    QWidget* createInteractionForAllContactPage(const Interaction&);
    QWidget* createTodoForAllContactPage(const Todo&);
    void toDelete();

    void fromDate_();
    void toDate_();
    void show_fromDate(QDate);
    void show_toDate(QDate);

    void ajoutInteraction();
    void boomNameChange(int);

    void addInteraction();
    void saveInteraction();
    void saveTodos(QStringList&);

    void searching();
    void searchingContact();
    void searchingInteraction();
    void searchingTodo();
    void selected(int);
    void selectedCombo(int);

    void exportJason();

signals:
    void refreshContacts(GestionContact&);
    void refreshInteractions(GestionContact&);
    void refreshTodos(GestionContact&);
    void todoToSave(QStringList&);
    // Signaux de recherche de contact
    void searchContactByNom(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByPrenom(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByNomPrenom(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByNomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByNomPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&);
    void searchContactByAllInfo(std::list<Contact>&, const QString&, const QString&, const QString&);
    // Signaux de recherche d'intéractions
    void searchContactInteraction(std::list<Contact>&, std::list<Interaction>&, const QString&, const QString&, const QString&);
    // Signaux de recherche de tâches
    void searchContactTodo(std::list<Interaction>&, std::list<Todo>&, const QString&, const QString&, const QString&);
};
#endif // MAINWINDOW_H
