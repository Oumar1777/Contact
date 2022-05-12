#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Contact");

    QObject::connect(&datas, SIGNAL(errorDataBase(const QString&)), this, SLOT(errorHappened(const QString&)));
    QObject::connect(&datas, SIGNAL(infoDataBase(const QString&)), this, SLOT(infoReceived(const QString&)));
    QObject::connect(this, SIGNAL(refreshContacts(GestionContact&)), &datas, SLOT(refreshingContacts(GestionContact&)));
    QObject::connect(this, SIGNAL(refreshInteractions(GestionContact&)), &datas, SLOT(refreshingInteractions(GestionContact&)));
    QObject::connect(this, SIGNAL(refreshTodos(GestionContact&)), &datas, SLOT(refreshingTodos(GestionContact&)));
    QObject::connect(&datas, SIGNAL(refreshed()), this, SLOT(showContact()));
    QObject::connect(this, SIGNAL(todoToSave(QStringList&)), this, SLOT(saveTodos(QStringList&)));
    // connexion signaux et slots de recherche de contact
    QObject::connect(this, SIGNAL(searchContactByNom(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactbyNom(std::list<Contact>&, const QString&, const QString&, const QString&)));
   QObject::connect(this, SIGNAL(searchContactByPrenom(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByPrenom(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByNomPrenom(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByNomPrenom(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByNomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByNomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByNomPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByNomPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByNomPrenomEntreprise(std::list<Contact>&, const QString&, const QString&, const QString&)));
    QObject::connect(this, SIGNAL(searchContactByAllInfo(std::list<Contact>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactByAllInfo(std::list<Contact>&, const QString&, const QString&, const QString&)));

    // connexion signaux et slots de recherche d'intéractions
     QObject::connect(this, SIGNAL(searchContactInteraction(std::list<Contact>&, std::list<Interaction>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactInteraction(std::list<Contact>&, std::list<Interaction>&, const QString&, const QString&, const QString&)));

     // connexion signaux et slots de recherche des tâches
     QObject::connect(this, SIGNAL(searchContactTodo(std::list<Interaction>&, std::list<Todo>&, const QString&, const QString&, const QString&)), &datas, SLOT(searchingContactTodo(std::list<Interaction>&, std::list<Todo>&, const QString&, const QString&, const QString&)));

    refresh();
    indice = 0; nbContact = gestC.getSize();

    // Barre de Menu
    QMenuBar* menu = new QMenuBar();
    // Menu Nouveau
    QMenu* menuAdd = new QMenu("&Nouveau");
        // Action ajouter un nouveau contact
        QAction* actionNewContact = new QAction("Contact");
        menuAdd->addAction(actionNewContact);
        // Action ajouter une nouvelle intéraction
        QAction* actionNewInteract = new QAction("Intéraction");
        menuAdd->addAction(actionNewInteract);
    menu->addMenu(menuAdd);
    // Menu Quitter
    QMenu* menuQuitter = new QMenu("&Quitter");
    menu->addMenu(menuQuitter);

    setMenuBar(menu);

    QObject::connect(actionNewContact, SIGNAL(triggered()), this, SLOT(ajoutContact()));
    QObject::connect(actionNewInteract, SIGNAL(triggered()), this, SLOT(ajoutInteraction()));
    QObject::connect(menuQuitter, SIGNAL(aboutToShow()), this, SLOT(Quitter()));


    createMainWidget();
}

MainWindow::~MainWindow()
{

}

/**
 * @brief MainWindow::errorHappened Affichage de messages d'erreur
 * @param msg : le message à afficher
 */
void MainWindow::errorHappened(const QString& msg)
{
    QMessageBox::critical(0,"ERREUR", msg, QMessageBox::Ok);
}

/**
 * @brief MainWindow::warningHappened Affichage de message d'avertissement
 * @param msg : Le message à afficher
 */
void MainWindow::warningHappened(const QString& msg)
{
    QMessageBox::warning(0,"ATTENTION", msg, QMessageBox::Ok);
}

/**
 * @brief MainWindow::infoReceived Affichage de message d'informations
 * @param msg : Le message à afficher
 */
void MainWindow::infoReceived(const QString& msg)
{
    QMessageBox::information(0,"INFO", msg, QMessageBox::Ok);
}

/**
 * @brief MainWindow::showContact Slot affichage gestionnaire dans le terminal
 */
void MainWindow::showContact()
{
    //qDebug() << gestC;
}

/**
 * @brief MainWindow::Quitter
 */
void MainWindow::Quitter()
{
    QApplication::quit();
}

/**
 * @brief MainWindow::refresh
 */
void MainWindow::refresh()
{
    emit refreshContacts(gestC);
    emit refreshInteractions(gestC);
    emit refreshTodos(gestC);
}

/**
 * @brief MainWindow::createMainWidget
 */
void MainWindow::createMainWidget()
{
    mainWidget = new QWidget();
    // Bouton tous les contacts
    QPushButton* allContats = new QPushButton("Voir tous les contacts");


    QGridLayout* grid = new QGridLayout();
    grid->addWidget(createContactForMainWidget(gestC.getContactAt((indice++)%nbContact)), 0,0,1,1);
    grid->addWidget(createContactForMainWidget(gestC.getContactAt((indice++)%nbContact)), 0,1,1,1);
    grid->addWidget(createContactForMainWidget(gestC.getContactAt((indice++)%nbContact)), 1,0,1,1);
    grid->addWidget(createContactForMainWidget(gestC.getContactAt((indice++)%nbContact)), 1,1,1,1);
    grid->addWidget(allContats, 2,0, 1, 2);

    QObject::connect(allContats, SIGNAL(clicked()), this, SLOT(seeAllContacts()));
    mainWidget->setLayout(grid);
    mainWidget->setStyleSheet("background-color:rgba(150,150,150,0.75);");
    setCentralWidget(mainWidget);
}

void MainWindow::seeAllContacts()
{
    searchResult.clear();
    searchResult = gestC.getListContact();
    createAllContactPageWidget();
}

/**
 * @brief MainWindow::createContactForMainWidget
 * @param contact
 * @return
 */
QWidget* MainWindow::createContactForMainWidget(const Contact& contact)
{
    QWidget* contactWidget = new QWidget();
    QLabel* nom = new QLabel("Nom:  "+contact.getNom());
    QLabel* prenom = new QLabel("Prénom:  "+contact.getPrenom());
    QLabel* entreprise = new QLabel("Entreprise: "+contact.getEntreprise());
    QLabel* email = new QLabel("Email : "+contact.getEmail());
    QLabel* tel = new QLabel("Téléphone : "+contact.getTelephone());
    QPushButton* more = new QPushButton("Voir le contact");
    more->setObjectName(contact.getID());
    QLabel* photo = new QLabel();
    photo->setScaledContents(true);
    photo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    photo->setPixmap(QPixmap(contact.getPhoto()));

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(photo, 0,0,6,1);
    grid->addWidget(nom, 0,1,1,1);
    grid->addWidget(prenom, 1,1,1,1);
    grid->addWidget(entreprise, 2,1,1,1);
    grid->addWidget(email, 3,1,1,1);
    grid->addWidget(tel, 4,1,1,1);
    grid->addWidget(more, 5,1,1,1);

    QObject::connect(more, SIGNAL(clicked()), this, SLOT(createContactPageWidget()));

    contactWidget->setLayout(grid);
    contactWidget->setStyleSheet("background-color:rgba(95,158,160,0.5);");

    return  contactWidget;
}

/**
 * @brief MainWindow::createTodoForMainWidget
 * @param todo
 * @return
 */
QWidget* MainWindow::createTodoForMainWidget(const Todo& todo)
{
    QWidget* todoWidget = new QWidget();

    QLabel* contenu = new QLabel("Tâche: "+todo.getContenu());
    QPushButton* voirTodo = new QPushButton("Aller à la tâche");
    QLabel* date = new QLabel();
    if(todo.getDate() == QDate::currentDate())
        date->setText("Pour Aujourd'hui");
    else
        date->setText("Pour le "+todo.getStringDate());

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget(contenu);
    vlayout->addWidget(date);
    vlayout->addWidget(voirTodo);

    todoWidget->setLayout(vlayout);
    todoWidget->setStyleSheet("background-color:rgba(32,178,170,0.85); border:0.2px;");
    return todoWidget;
}

/**
 * @brief MainWindow::createContactPageWidget
 * @param contact
 */
void MainWindow::createContactPageWidget()
{
    QPushButton* button = (QPushButton*)sender();
    QString id = button->objectName();
    Contact contact = gestC.getContactByID(id);

    contactPageWidget = new QWidget();
    QLabel* nom = new QLabel("Nom:  "+contact.getNom());
    QLabel* prenom = new QLabel("Prénom:  "+contact.getPrenom());
    QLabel* entreprise = new QLabel("Entreprise: "+contact.getEntreprise());
    QLabel* email = new QLabel("Email: "+contact.getEmail());
    QLabel* tel = new QLabel("Téléphone: "+contact.getTelephone());
    QLabel* datecreation = new QLabel("Date de création: "+contact.getStringDateCreation());
    QLabel* datelastmodif = new QLabel("Date de dernière modification: "+contact.getStringDateLastModif());
    QLabel* photo = new QLabel();
    photo->setScaledContents(true);
    photo->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    photo->setPixmap(QPixmap(contact.getPhoto()));

    QWidget * lesInteractions = new QWidget();
    QVBoxLayout * vlayout = new QVBoxLayout();
    for(auto interact : gestC.getAllContactInteraction(contact.getID()).getListInteraction())
        vlayout->addWidget(createInteractionWidgetForContactPage(interact));
    lesInteractions->setLayout(vlayout);
    QScrollArea* scrollAreaInteraction = new QScrollArea();
    scrollAreaInteraction->setWidget(lesInteractions);
    scrollAreaInteraction->setWidgetResizable(true);

    QWidget * zoneButton = new QWidget();
        QPushButton * btAddinteract = new QPushButton("Ajouter une intéraction");
        btAddinteract->setObjectName(id);
        QPushButton * btModification = new QPushButton("Modifier le contact");
        btModification->setObjectName(id);
        QPushButton * btRetour = new QPushButton("Accueil");
        QHBoxLayout * hlayout = new QHBoxLayout();
        hlayout->addWidget(btAddinteract);
        hlayout->addWidget(btModification);
        hlayout->addWidget(btRetour);
    zoneButton->setLayout(hlayout);

    QObject::connect(btRetour, SIGNAL(clicked()), this, SLOT(createMainWidget()));
    QObject::connect(btModification, SIGNAL(clicked()), this, SLOT(modificationContact()));
    QObject::connect(btAddinteract, SIGNAL(clicked()), this, SLOT(addInteraction()));

    QGridLayout* grid = new QGridLayout();
    grid->addWidget(photo, 0,0,7,1);
    grid->addWidget(nom, 0,1,1,1);
    grid->addWidget(prenom, 1,1,1,1);
    grid->addWidget(entreprise, 2,1,1,1);
    grid->addWidget(email, 3,1,1,1);
    grid->addWidget(tel, 4,1,1,1);
    grid->addWidget(datecreation, 5,1,1,1);
    grid->addWidget(datelastmodif, 6,1,1,1);
    grid->addWidget(scrollAreaInteraction, 7, 0, 2,2);
    grid->addWidget(zoneButton, 9,0,1,2);

    contactPageWidget->setLayout(grid);
    contactPageWidget->setStyleSheet("background-color:rgba(150,150,150,0.75);");
    setCentralWidget(contactPageWidget);
}

/**
 * @brief MainWindow::createInteractionWidgetForContactPage
 * @param interact
 * @return
 */
QWidget* MainWindow::createInteractionWidgetForContactPage(const Interaction& interact)
{
    QWidget* interaction = new QWidget();
        QLabel* contenu = new QLabel("Intéraction : "+interact.getContenu());
        QLabel* date = new QLabel("Date de l'intéraction : " + interact.getStringDate());
        QVBoxLayout* vlayout = new QVBoxLayout();
        vlayout->addWidget(contenu);
        vlayout->addWidget(date);
        for(auto todo : gestC.getGestTodo()->getAllInteractionTodo(interact.getID()).getlistTodo())
            vlayout->addWidget(createTodoWidgetForContactPage(todo));
    interaction->setLayout(vlayout);
    interaction->setStyleSheet("background-color:rgba(224,255,255,1);");
    return interaction;
}

/**
 * @brief MainWindow::createTodoForMainWidget
 * @param todo
 * @return
 */
QWidget* MainWindow::createTodoWidgetForContactPage(const Todo& todo)
{
    QWidget* todoWidget = new QWidget();

    QLabel* contenu = new QLabel("Tâche: "+todo.getContenu());
    QLabel* date = new QLabel();
    if(todo.getDate() == QDate::currentDate())
        date->setText("Pour Aujourd'hui");
    else
        date->setText("Pour le "+todo.getStringDate());

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget(contenu);
    vlayout->addWidget(date);

    todoWidget->setLayout(vlayout);
    todoWidget->setStyleSheet("background-color:rgba(32,178,170,0.85);");
    return todoWidget;
}

/**
 * @brief MainWindow::ajoutContact
 */
void MainWindow::ajoutContact()
{
    QFrame * f_contact= new QFrame;
    QGridLayout * g_contact= new QGridLayout;
    QFormLayout * formulaireContact= new QFormLayout;

    c_photo = new QLabel("Photo s'affiche ici");
        fichier = "../Projet/Files/defaultpic";
        adapterPhoto();
    c_nom= new QLineEdit;
    c_prenom= new QLineEdit;
    c_entreprise= new QLineEdit;
    c_numero= new QLineEdit;
        c_numero->setText("");
        c_numero->setInputMask("9999999999");
    c_email= new QLineEdit;

    QHBoxLayout *hLayout= new QHBoxLayout;

    QPushButton * c_save= new QPushButton("Enregistrer");
    QPushButton * c_reset= new QPushButton("Annuler");
    hLayout->addWidget(c_reset);
    hLayout->addWidget(c_save);


    QPushButton * c_addPic= new QPushButton("Ajouter une photo");

    formulaireContact->addRow("Nom: ", c_nom);
    formulaireContact->addRow("Prenom: ", c_prenom);
    formulaireContact->addRow("Entreprise: ", c_entreprise);
    formulaireContact->addRow("Email: ", c_email);
    formulaireContact->addRow("Numero: ", c_numero);
    formulaireContact->addRow(c_addPic);

    g_contact->addWidget(c_photo, 0, 0, 2, 1);
    g_contact->addLayout(formulaireContact, 2, 0,1 , 1);
    g_contact->addLayout(hLayout, 3, 0, 1, 1);

    f_contact->setLayout(g_contact);
    f_contact->setStyleSheet("background-color:rgba(150,150,150,0.75);");

    setCentralWidget(f_contact);

    //SousMenuContact
    connect(c_addPic, SIGNAL(clicked()), this, SLOT(insertContactPic()));
    connect(c_save, SIGNAL(clicked(bool)), this, SLOT(verifier()));
    connect(c_reset, SIGNAL(clicked(bool)), this, SLOT(resetContact()));
}

/**
 * @brief MainWindow::insertContactPic
 */
void MainWindow::insertContactPic()
{
    fichier = QFileDialog::getOpenFileName(this, "Ouverture d'un fichier", QString(), "Image(*.png)");
    adapterPhoto();
}

/**
 * @brief MainWindow::adapterPhoto
 */
void MainWindow::adapterPhoto()
{
    c_photo->setPixmap(QPixmap(fichier));
    c_photo->setScaledContents(true);
    c_photo->setSizePolicy(QSizePolicy:: Ignored, QSizePolicy::Ignored);
}

/**
 * @brief MainWindow::verifier
 */
void MainWindow::verifier()
{
    Contact contact;
    bool allright = true;

    if(c_nom->text() == "") allright = false;
    else  contact.setNom(c_nom->text());
    if(c_prenom->text() == "") allright = false;
    else contact.setPrenom(c_prenom->text());
    if(c_entreprise->text() == "") allright = false;
    else contact.setEntreprise(c_entreprise->text());
    if(c_numero->text() == "") allright = false;
    else contact.setTelephone(c_numero->text());

    if(!allright)
        errorHappened("Erreur !! Veuillez remplir les champs Nom, Prénom, Entreprise et Numéro");
    else if(!contact.setEmail(c_email->text()))
    {
        errorHappened("Adresse mail incorrecte !!");
        allright = false;
    }

    if(allright)
    {
        if(fichier != "../Projet/Files/defaultpic")
        {
            QString destination = "../Projet/Files/"+contact.getPrenom();
            int i = 0;
            while(!(QFile::copy(fichier, destination)))
            {
                QString num;
                num.setNum(++i);
                destination = "../Projet/Files/"+contact.getPrenom()+num;
            }
            fichier = destination;
        }

        contact.setPhoto(fichier);
        saveContact(contact);
    }

}

/**
 * @brief MainWindow::saveContact
 * @param contact
 */
void  MainWindow::saveContact(const Contact& contact)
{
    datas.addContact(contact);
    refreshContacts(gestC);
    nbContact++;
    createMainWidget();
}

/**
 * @brief MainWindow::deleteContact
 * @param idcontact
 */
void MainWindow::deleteContact(const QString& idcontact)
{
    int ret = QMessageBox::warning(0, "ATTENTION !!","Le contact sera définitivement supprimé.", QMessageBox::Cancel|QMessageBox::Ok, QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        datas.removeConctact(idcontact);
        QString photo = gestC.getContactByID(idcontact).getPhoto();
        if(photo != "../Projet/Files/defaultpic")
            QFile::remove(photo);
        refresh();
        nbContact--;
        seeAllContacts();
    }
}

/**
 * @brief MainWindow::resetContact
 */
void MainWindow::resetContact()
{
    QMessageBox::warning(this, "Warning !!!" ,"Aucune modification n'a été pris en compte");
    createMainWidget();
}

/**
 * @brief MainWindow::createAllContactPageWidget
 */
void MainWindow::createAllContactPageWidget()
{
    allContactPageWidget = new QWidget;
    selection = 0;
        QGridLayout *c_grid= new QGridLayout;

        //afffichage label
        QString text, nbSearch, nbCont;

        if(sender()->objectName() == "2")
        {
            text = "Les tâches : ";
            nbSearch.setNum(listTodoModified.size());
            nbCont.setNum(gestC.getGestTodo()->getSize());
        }
        else if(sender()->objectName() == "1")
        {
            text = "Les intéractions : ";
            nbSearch.setNum(listInteractionModified.size());
            nbCont.setNum(gestC.getGestInteraction()->getSize());
        }
        else
        {
            text = "Tous les contacts : ";
            nbSearch.setNum(searchResult.size());
            nbCont.setNum(nbContact);
        }

        QLabel * tousLesContacts= new QLabel(text+nbSearch+"/"+nbCont);
        tousLesContacts->setAlignment(Qt::AlignCenter);
        tousLesContacts->setFont(QFont("Times", 30));

        //search
        QHBoxLayout * s_horizontal= new QHBoxLayout;
        search= new QLineEdit;
        boom= new QPushButton("Recherche");
        boom->setObjectName("0");
        QComboBox* combo = new QComboBox();
        combo->addItem("Contacts");
        combo->addItem("Intéractions");
        combo->addItem("Tâches");
        s_horizontal->addWidget(search);
        s_horizontal->addWidget(combo);
        s_horizontal->addWidget(boom);

        //checkboxes
        QHBoxLayout *cb_horizontal= new QHBoxLayout;
        cb_nom = new QCheckBox("Nom");
        cb_prenom= new QCheckBox("Prenom");
        cb_entreprise= new QCheckBox("Entreprise");

        cb_horizontal->addWidget(cb_nom);
        cb_horizontal->addWidget(cb_prenom);
        cb_horizontal->addWidget(cb_entreprise);

        //checkDates
        QHBoxLayout * d_horizontal= new QHBoxLayout;

        b_from = new QPushButton("Du");
        b_to= new QPushButton("Au");

        d_horizontal->addWidget(b_from);
        d_horizontal->addWidget(b_to);

        // retour accueil
        QPushButton * btaccueil = new QPushButton("Aller à l'accueil");
            //fusionner tout
            c_grid->addWidget(tousLesContacts, 0, 0, 1 , 1);
            c_grid->addLayout(s_horizontal, 1, 0, 1, 1);
            c_grid->addLayout(cb_horizontal, 2, 0, 1, 1);
            c_grid->addLayout(d_horizontal, 3, 0, 1, 1);
                QWidget * zoneContact = new QWidget();
                    QVBoxLayout * vlayout = new QVBoxLayout();
                    if(sender()->objectName() == "1")
                    {
                        for(auto interact : listInteractionModified)
                            vlayout->addWidget(createInteractionForAllContactPage(interact));
                    }
                    else if (sender()->objectName() == "2")
                    {
                        for(auto todo : listTodoModified)
                            vlayout->addWidget(createTodoForAllContactPage(todo));
                    }
                    else
                    {
                        for(auto contact : searchResult)
                            vlayout->addWidget(createContactForAllContactPage(contact));
                    }
                    zoneContact->setLayout(vlayout);
            QScrollArea * scroll = new QScrollArea();
            scroll->setWidget(zoneContact);
            scroll->setWidgetResizable(true);
            c_grid->addWidget(scroll, 4, 0, 1, 1);
            c_grid->addWidget(btaccueil, 5, 0, 1, 1);

        allContactPageWidget->setLayout(c_grid);
        allContactPageWidget->setStyleSheet("background-color:rgba(150,150,150,0.75);");
        // Connexion boutons
        connect(b_from, SIGNAL(clicked(bool)), this, SLOT(fromDate_()));
        connect(b_to, SIGNAL(clicked(bool)), this, SLOT(toDate_()));
        connect(btaccueil,SIGNAL(clicked()), SLOT(createMainWidget()));
        connect(boom, SIGNAL(clicked()), this, SLOT(searching()));
        // Connexion CheckBox
        connect(cb_nom, SIGNAL(stateChanged(int)), this, SLOT(selected(int)));
        connect(cb_prenom, SIGNAL(stateChanged(int)), this, SLOT(selected(int)));
        connect(cb_entreprise, SIGNAL(stateChanged(int)), this, SLOT(selected(int)));
        connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(selectedCombo(int)));
    setCentralWidget(allContactPageWidget);
}

/**
 * @brief MainWindow::fromDate_
 */
void MainWindow::fromDate_()
{
    calendar_from= new QCalendarWidget;
    calendar_from->setGridVisible(true);
    calendar_from->show();
    calendar_from->setWindowTitle("Du");
    connect(calendar_from, SIGNAL(clicked(QDate)), this, SLOT(show_fromDate(QDate)));
}

/**
 * @brief MainWindow::toDate_
 */
void MainWindow::toDate_()
{
    calendar_to= new QCalendarWidget;

    calendar_to->setGridVisible(true);

    calendar_to->show();
    calendar_to->setWindowTitle("Au");
    connect(calendar_to, SIGNAL(clicked(QDate)), this, SLOT(show_toDate(QDate)));
}

/**
 * @brief MainWindow::show_fromDate
 * @param date
 */
void MainWindow::show_fromDate(QDate date)
{
    b_from->setText(date.toString("yyyy/MM/dd"));
}

/**
 * @brief MainWindow::show_toDate
 * @param date
 */
void MainWindow::show_toDate(QDate date)
{
    b_to->setText(date.toString("yyyy/MM/dd"));
}

/**
 * @brief MainWindow::createContactForAllContactPage
 * @param contact
 * @return
 */
QWidget* MainWindow::createContactForAllContactPage(const Contact& contact)
{
    QWidget* contactWidget = new QWidget();

    QGridLayout *grid= new QGridLayout;
        QHBoxLayout *bt_horizontal= new QHBoxLayout;
        QPushButton *c_seeAll= new QPushButton("Voir le contact");
        c_seeAll->setObjectName(contact.getID());
        QPushButton *c_delete= new QPushButton("Supprimer");
        c_delete->setObjectName(contact.getID());
        QPushButton *c_update= new QPushButton("Modifier");
        c_update->setObjectName(contact.getID());

        bt_horizontal->addWidget(c_seeAll);
        bt_horizontal->addWidget(c_update);
        bt_horizontal->addWidget(c_delete);

        QLabel *photo= new QLabel;
            photo->setPixmap(contact.getPhoto());
            photo->setScaledContents(true);
            photo->setSizePolicy(QSizePolicy:: Ignored, QSizePolicy::Ignored);
        QLabel *nom= new QLabel("Nom: "+contact.getNom());
        QLabel *prenom= new QLabel("Prenom: "+contact.getPrenom());
        QLabel *email= new QLabel("Email: "+contact.getEmail());
        QLabel *entreprise= new QLabel("Entreprise: "+contact.getEntreprise());
        QLabel *numero= new QLabel("Numero: "+contact.getTelephone());
        QLabel *datecreation = new QLabel("Date de création: "+contact.getStringDateCreation());
        QLabel *dateLastModif = new QLabel("Dernière modification: "+contact.getStringDateLastModif());

        grid->addWidget(photo, 0, 0, 7, 1);
        grid->addWidget(nom, 0, 1, 1, 1);
        grid->addWidget(prenom, 1, 1, 1, 1);
        grid->addWidget(entreprise, 2, 1, 1, 1);
        grid->addWidget(email, 3, 1, 1, 1);
        grid->addWidget(numero, 4, 1, 1, 1);
        grid->addWidget(datecreation, 5, 1, 1, 1);
        grid->addWidget(dateLastModif, 6, 1, 1, 1);
        grid->addLayout(bt_horizontal, 7, 0, 1, 2);

    contactWidget->setLayout(grid);
    contactWidget->setStyleSheet("background-color:rgba(95,158,160,0.5);");

    QObject::connect(c_seeAll, SIGNAL(clicked()), this, SLOT(createContactPageWidget()));
    QObject::connect(c_delete, SIGNAL(clicked()), this, SLOT(toDelete()));
    QObject::connect(c_update, SIGNAL(clicked()), this, SLOT(modificationContact()));

    return contactWidget;
}

/**
 * @brief MainWindow::createInteractionForAllContactPage
 * @param interact
 * @return
 */
QWidget* MainWindow::createInteractionForAllContactPage(const Interaction& interact)
{
    QWidget* interaction = new QWidget();
        QLabel* contact = new QLabel("Contact : "+interact.getContact()->getNom()+" "+interact.getContact()->getPrenom());
            contact->setStyleSheet("background-color:rgba(95,158,160,0.5);");
        QLabel* contenu = new QLabel("Intéraction : "+interact.getContenu());
        QLabel* date = new QLabel("Date de l'intéraction : " + interact.getStringDate());
        QVBoxLayout* vlayout = new QVBoxLayout();
        vlayout->addWidget(contact);
        vlayout->addWidget(contenu);
        vlayout->addWidget(date);
        for(auto todo : gestC.getGestTodo()->getAllInteractionTodo(interact.getID()).getlistTodo())
            vlayout->addWidget(createTodoWidgetForContactPage(todo));
    interaction->setLayout(vlayout);
    interaction->setStyleSheet("background-color:rgba(224,255,255,1);");
    return interaction;
}

/**
 * @brief MainWindow::createTodoForAllContactPage
 * @param todo
 * @return
 */
QWidget* MainWindow::createTodoForAllContactPage(const Todo& todo)
{
    QWidget* todoWidget = new QWidget();

    QLabel* contact = new QLabel("Contact : "+todo.getInteraction()->getContact()->getNom() + " "+todo.getInteraction()->getContact()->getPrenom());
        contact->setStyleSheet("background-color:rgba(95,158,160,0.5);");
    QLabel* contenu = new QLabel("Tâche: "+todo.getContenu());
    QLabel* date = new QLabel();
    if(todo.getDate() == QDate::currentDate())
        date->setText("Pour Aujourd'hui");
    else
        date->setText("Pour le "+todo.getStringDate());

    QVBoxLayout* vlayout = new QVBoxLayout();
    vlayout->addWidget(contact);
    vlayout->addWidget(contenu);
    vlayout->addWidget(date);

    todoWidget->setLayout(vlayout);
    todoWidget->setStyleSheet("background-color:rgba(32,178,170,0.85);");

    return todoWidget;
}

/**
 * @brief MainWindow::toDelete
 */
void MainWindow::toDelete()
{
    QPushButton * clickedButton = (QPushButton *)sender();
    QString idContact = clickedButton->objectName();
    deleteContact(idContact);
    seeAllContacts();
}

/**
 * @brief MainWindow::ajoutInteraction Ce Slot se déclenche lorsque l'action interaction du menu Ajouter est cliqué.
 */
void MainWindow::ajoutInteraction()
{

    QDialog *b_dialog = new QDialog(this);
    b_dialog->setAutoFillBackground(true);
    b_dialog->setWindowTitle("Creer nouvelle interaction");
    QHBoxLayout *hLayout= new QHBoxLayout;
    boom= new QPushButton("Valider", b_dialog);
    boom->setDisabled(true);
    QComboBox *list= new QComboBox;
    list->addItem("List des conctacts");
    for(auto contact : gestC.getListContact())
        list->addItem(contact.getNom()+" "+contact.getPrenom());

    hLayout->addWidget(list);
    hLayout->addWidget(boom);
    b_dialog->setLayout(hLayout);
    b_dialog->setStyleSheet("background-color:rgba(150,150,150,0.75);");

    QObject::connect(list, SIGNAL(currentIndexChanged(int)), this, SLOT(boomNameChange(int)));
    QObject::connect(boom, SIGNAL(clicked()), this, SLOT(createContactPageWidget()));

    b_dialog->show();
}

/**
 * @brief MainWindow::addInteraction Ce slot se déclenche lorsque le bouton ajouter une intéraction est cliqué dans la page d'affichage du contact.
 */
void MainWindow::addInteraction()
{
    // Récupération Info contact correspondant
    QPushButton * clickedButton = (QPushButton * )sender();
    QString idcontact = clickedButton->objectName();

    QWidget * fenetreAddInteract = new QWidget();
    fenetreAddInteract->setWindowTitle("Ajouter une nouvelle intéraction");
        QPushButton * buttonValider = new QPushButton("Enregistrer l'intéraction");
            buttonValider->setObjectName(idcontact);
        QVBoxLayout * vlayout = new QVBoxLayout();
        forAddInteraction = new QTextEdit();
        vlayout->addWidget(forAddInteraction);
        vlayout->addWidget(buttonValider);
    fenetreAddInteract->setLayout(vlayout);
    fenetreAddInteract->show();

    QObject::connect(buttonValider, SIGNAL(clicked()), this, SLOT(saveInteraction()));
    QObject::connect(buttonValider, SIGNAL(clicked()), fenetreAddInteract, SLOT(close()));
}

/**
 * @brief MainWindow::saveInteraction
 */
void MainWindow::saveInteraction()
{
    // Récupération Info contact correspondant
    QPushButton * clickedButton = (QPushButton * )sender();
    QString idcontact = clickedButton->objectName();

    QTextDocument * document = forAddInteraction->document();
    QTextCursor cursor(document);
    QTextDocument::FindFlag flag = (QTextDocument::FindFlag) 0;

    // Recupération de la première ligne
    QString contenu = forAddInteraction->toPlainText().section(QChar(10), 0);
    if(contenu.contains("@todo ", Qt::CaseInsensitive))
        //Si elle contient @todo alors le contenu de l'intéraction est vide
        contenu = "";

    // Expression régulière toutes les lignes commençant par "@todo"
    QRegularExpression expr("^@todo .*$");
    QStringList listTodo;

    while(!cursor.isNull())
    {
        cursor = document->find(expr, cursor.position(), flag);
        if(!cursor.isNull())
        {
            QTextBlock bloq = cursor.block();
            listTodo.append(bloq.text());
        }
    }

    qDebug() << contenu;

    Interaction interact;
    interact.setContact(gestC.getContactAdr(idcontact));
    interact.setContenu(contenu);
    datas.addInteraction(interact);

    emit todoToSave(listTodo);
    createContactPageWidget();
}

/**
 * @brief MainWindow::saveTodos
 * @param listTodo
 */
void MainWindow::saveTodos(QStringList& listTodo)
{
    // Rafraichissement list interactions
    refreshInteractions(gestC);

    for(auto saisie : listTodo)
    {
        Todo todo;
        if(saisie.contains(" @date ", Qt::CaseInsensitive))
        {
            QStringList leTodo = saisie.split(' ',Qt::SkipEmptyParts);
            QString contenu;
            int i = 1;
            while(leTodo.at(i).compare("@date", Qt::CaseInsensitive) != 0)
            {
                contenu.append(leTodo.at(i)+" ");
                i++;
            }
            todo.setContenu(contenu);
            if(!(todo.setDateFromString(leTodo.at(i+1))))
                errorHappened("La date saisie est incorrecte !! La tâche sera initialisé à la date courante");
        }
        else
            todo.setContenu(saisie.section(' ', 1));

        // Todo asssocié à la dernière intéraction enregistrée
        todo.setInteraction(gestC.getGestInteraction()->getLastSavedInteraction());
        datas.addTodo(todo);
    }
    // Rafraichisement de la liste des todos
    refreshTodos(gestC);
    // retour page contact
}

/**
 * @brief MainWindow::boomNameChange
 * @param index
 */
void MainWindow::boomNameChange(int index)
{
    if(index == 0)
        boom->setDisabled(true);
    else
    {
        boom->setEnabled(true);
        boom->setObjectName(gestC.getContactAt(index - 1).getID());
    }
}

/**
 * @brief MainWindow::modificationContact
 */
void MainWindow::modificationContact()
{
    QPushButton* clickedButton = (QPushButton*)sender();
    QString idContact = clickedButton->objectName();
    Contact contact = gestC.getContactByID(idContact);

    QFrame * f_contact= new QFrame;
    QGridLayout * g_contact= new QGridLayout;
    QFormLayout * formulaireContact= new QFormLayout;

    c_photo = new QLabel("Photo s'affiche ici");
        c_photo->setMinimumHeight(50);
        fichier = contact.getPhoto();
        adapterPhoto();
    c_nom= new QLineEdit(contact.getNom());
    c_prenom= new QLineEdit(contact.getPrenom());
    c_entreprise= new QLineEdit(contact.getEntreprise());
    c_numero= new QLineEdit(contact.getTelephone());
        c_numero->setInputMask("9999999999");
    c_email= new QLineEdit(contact.getEmail());

    QHBoxLayout *hLayout= new QHBoxLayout;

    QPushButton * c_save= new QPushButton("Enregistrer");
    c_save->setObjectName(idContact);
    QPushButton * c_reset= new QPushButton("Annuler");
    QPushButton * c_delete= new QPushButton("Supprimer le contact");
    c_delete->setObjectName(idContact);
    hLayout->addWidget(c_reset);
    hLayout->addWidget(c_delete);
    hLayout->addWidget(c_save);


    QPushButton * c_addPic= new QPushButton("Modifier la photo");

    formulaireContact->addRow("Nom: ", c_nom);
        c_nom->setObjectName(idContact);
    formulaireContact->addRow("Prenom: ", c_prenom);
        c_prenom->setObjectName(idContact);
    formulaireContact->addRow("Entreprise: ", c_entreprise);
        c_entreprise->setObjectName(idContact);
    formulaireContact->addRow("Email: ", c_email);
        c_email->setObjectName(idContact);
    formulaireContact->addRow("Numero: ", c_numero);
        c_numero->setObjectName(idContact);
    formulaireContact->addRow(c_addPic);

    QWidget* lesInteractions = new QWidget();
    QVBoxLayout * vlayout = new QVBoxLayout();
    for(auto interact : gestC.getAllContactInteraction(idContact).getListInteraction())
    {
        vlayout->addWidget(createInteractionForModificationContact(interact));
    }
    lesInteractions->setLayout(vlayout);
    QScrollArea * scroll = new QScrollArea();
    scroll->setWidget(lesInteractions);
    scroll->setWidgetResizable(true);
    scroll->setMaximumHeight(250);

    g_contact->addWidget(c_photo, 0, 0, 2, 1);
    g_contact->addLayout(formulaireContact, 2, 0, 1, 1);
    g_contact->addWidget(scroll, 3, 0, 1, 1);
    g_contact->addLayout(hLayout, 4, 0, 1, 1);

    f_contact->setLayout(g_contact);
    f_contact->setStyleSheet("background-color:rgba(150,150,150,0.75);");

    contactModified = gestC.getContactByID(idContact);
    listTodoModified.clear();
    listInteractionModified.clear();

    setCentralWidget(f_contact);

    connect(c_addPic, SIGNAL(clicked()), this, SLOT(insertContactPic()));
    connect(c_save, SIGNAL(clicked(bool)), this, SLOT(saveModification()));
    connect(c_reset, SIGNAL(clicked(bool)), this, SLOT(resetContact()));
    connect(c_delete, SIGNAL(clicked(bool)), this, SLOT(toDelete()));

    connect(c_nom, SIGNAL(editingFinished()), this, SLOT(contactIsModified()));
    connect(c_prenom, SIGNAL(editingFinished()), this, SLOT(contactIsModified()));
    connect(c_entreprise, SIGNAL(editingFinished()), this, SLOT(contactIsModified()));
    connect(c_numero, SIGNAL(editingFinished()), this, SLOT(contactIsModified()));
    connect(c_email, SIGNAL(editingFinished()), this, SLOT(contactIsModified()));
}

/**
 * @brief MainWindow::createInteractionForModificationContact
 * @param interact
 * @return
 */
QWidget* MainWindow::createInteractionForModificationContact(const Interaction& interact)
{
    QWidget * interactionWidget = new QWidget();
        QFormLayout * formLayout = new QFormLayout();

            QLineEdit * contenu = new QLineEdit(interact.getContenu());
                contenu->setObjectName(interact.getID());
            QLineEdit * dateInt = new QLineEdit(interact.getDate().toString("dd/MM/yyyy"));
                dateInt->setObjectName(interact.getID());
                dateInt->setMaxLength(10);
            QPushButton * deleteinteraction = new QPushButton("Supprimer l'intéraction");
            deleteinteraction->setObjectName(interact.getID());
            QHBoxLayout * hlayout1 = new QHBoxLayout();
                hlayout1->addWidget(contenu);
                hlayout1->addWidget(deleteinteraction);
            formLayout->addRow("Intéraction:", hlayout1);
            formLayout->addRow("Date de l'intéraction:", dateInt);

            for(auto todo : gestC.getGestTodo()->getAllInteractionTodo(interact.getID()).getlistTodo())
            {
                QLineEdit * tache = new QLineEdit(todo.getContenu());
                tache->setObjectName(todo.getID());
                tache->setStyleSheet("background-color:rgba(32,178,170,0.85);");

                QLineEdit * date = new QLineEdit(todo.getStringDate());
                date->setObjectName(todo.getID());
                date->setMaxLength(10);
                date->setStyleSheet("background-color:rgba(32,178,170,0.85);");

                QPushButton * deleteTodo = new QPushButton("Supprimer la tâche");
                deleteTodo->setStyleSheet("background-color:rgba(32,178,170,0.85);");

                deleteTodo->setObjectName(todo.getID());
                QHBoxLayout * hlayout2 = new QHBoxLayout();
                    hlayout2->addWidget(tache);
                    hlayout2->addWidget(deleteTodo);
                formLayout->addRow("Tâche :", hlayout2);
                formLayout->addRow("Date:", date);
                QObject::connect(deleteTodo, SIGNAL(clicked()), this, SLOT(deleteThisTodo()));
                QObject::connect(tache, SIGNAL(editingFinished()), this, SLOT(todoContenuModified()));
                QObject::connect(date, SIGNAL(editingFinished()), this, SLOT(todoDateModified()));

            }
        QObject::connect(deleteinteraction, SIGNAL(clicked()), this, SLOT(deleteThisInteraction()));
        QObject::connect(contenu, SIGNAL(editingFinished()), this, SLOT(interactionContenuModified()));
        QObject::connect(dateInt, SIGNAL(editingFinished()), this, SLOT(interactionDateModified()));
        interactionWidget->setLayout(formLayout);
        interactionWidget->setStyleSheet("background-color:rgba(224,255,255,1);");
    return interactionWidget;
}

/**
 * @brief MainWindow::deleleThisTodo
 */
void MainWindow::deleteThisTodo()
{
    QPushButton * clickedButton = (QPushButton *)sender();
    QString idTodo = clickedButton->objectName();

    int ret = QMessageBox::warning(0, "ATTENTION !!","La tâche sera définitivement supprimée.", QMessageBox::Cancel|QMessageBox::Ok, QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        sender()->setObjectName(gestC.getTodo(idTodo).getInteraction()->getContact()->getID());

        datas.removeTodo(idTodo);
        refresh();

        modificationContact();
    }

}

/**
 * @brief MainWindow::deleteThisInteraction
 */
void MainWindow::deleteThisInteraction()
{
    QPushButton * clickedButton = (QPushButton *)sender();
    QString idInteraction = clickedButton->objectName();

    int ret = QMessageBox::warning(0, "ATTENTION !!","L'intéraction sera définitivement supprimée ainsi que toutes les tâches asssociées.", QMessageBox::Cancel|QMessageBox::Ok, QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
        sender()->setObjectName(gestC.getInteraction(idInteraction).getContact()->getID());

        datas.removeInteraction(idInteraction);
        refresh();

        modificationContact();
    }
}

/**
 * @brief MainWindow::todoModified
 */
void MainWindow::todoContenuModified()
{
    QLineEdit * lineEdited = (QLineEdit *)sender();
    QString idTodo = lineEdited->objectName();

    auto it = listTodoModified.begin();
    bool found = false;
    while(it != listTodoModified.end() && !found)
    {
        if(it->getID() == idTodo)
        {
            // Si la tâche est déjà dans la liste des modifications
            it->setContenu(lineEdited->text());
            found = true;
        }
        else
            it++;
    }
    // Si la tâche n'est pas dans la liste des modifications
    if(!found)
    {
        Todo todo = gestC.getTodo(idTodo);
        todo.setContenu(lineEdited->text());
        listTodoModified.push_back(todo);
    }
}

/**
 * @brief MainWindow::todoDateModified
 */
void MainWindow::todoDateModified()
{
    QLineEdit * lineEdited = (QLineEdit *)sender();
    QString idTodo = lineEdited->objectName();

    auto it = listTodoModified.begin();
    bool found = false;
    while(it != listTodoModified.end() && !found)
    {
        if(it->getID() == idTodo)
        {
            // Si la tâche est déjà dans la liste des modifications
            if(!(it->setDateFromString(lineEdited->text())))
            {
                warningHappened("La date saisie est invalide !! Réessayer !!");
                lineEdited->setText(it->getStringDate());
            }
            found = true;
        }
        else
            it++;
    }
    // Si la tâche n'est pas dans la liste des modifications
    if(!found)
    {
        Todo todo = gestC.getTodo(idTodo);
        if(todo.setDateFromString(lineEdited->text()))
            listTodoModified.push_back(todo);
        else
        {
            warningHappened("La date saisie est invalide !! Réessayer !!");
            lineEdited->setText(todo.getStringDate());
        }
    }
}

/**
 * @brief MainWindow::interactionModified
 */
void MainWindow::interactionContenuModified()
{
    QLineEdit * lineEdited = (QLineEdit *)sender();
    QString idInteract = lineEdited->objectName();

    auto it = listInteractionModified.begin();
    bool found = false;
    while(it != listInteractionModified.end() && !found)
    {
        if(it->getID() == idInteract)
        {
            // Si l'interaction est déjà dans la liste des modifications
            it->setContenu(lineEdited->text());
            found = true;
        }
        else
            it++;
    }
    // Si l'intéraction n'est pas dans la liste des modifications
    if(!found)
    {
        Interaction interact = gestC.getInteraction(idInteract);
        interact.setContenu(lineEdited->text());
        listInteractionModified.push_back(interact);
    }

}

/**
 * @brief MainWindow::interactionDateModified
 */
void MainWindow::interactionDateModified()
{
    QLineEdit * lineEdited = (QLineEdit *)sender();
    QString idInteract = lineEdited->objectName();

    auto it = listInteractionModified.begin();
    bool found = false;
    while(it != listInteractionModified.end() && !found)
    {
        if(it->getID() == idInteract)
        {
            // Si l'interaction est déjà dans la liste des modifications
            if(!(it->setDateFromString(lineEdited->text())))
            {
                warningHappened("La date saisie est invalide !! Réessayer !!");
                lineEdited->setText(it->getStringDate());
            }

            found = true;
        }
        else
            it++;
    }
    // Si l'intéraction n'est pas dans la liste des modifications
    if(!found)
    {
        Interaction interact = gestC.getInteraction(idInteract);
        if(interact.setDateFromString(lineEdited->text()))
            listInteractionModified.push_back(interact);
        else
        {
            warningHappened("La date saisie est invalide !! Réessayer !!");
            lineEdited->setText(interact.getStringDate());
        }
    }
}

/**
 * @brief MainWindow::contactIsModified Ce Slot se déclenche lorsque les informations d'un contact sont modifiées.
 */
void MainWindow::contactIsModified()
{
    QLineEdit * lineEdited = (QLineEdit *)sender();
    QString idContact = lineEdited->objectName();

    contactModified.setNom(c_nom->text());
    contactModified.setPrenom(c_prenom->text());
    contactModified.setEntreprise(c_entreprise->text());
    contactModified.setTelephone(c_numero->text());
    if(!(contactModified.setEmail(c_email->text())))
    {
        errorHappened("Adresse Mail Incorrecte");
        c_email->setText(contactModified.getEmail());
    }

    contactModified.modification();
}

/**
 * @brief MainWindow::saveModification Enregistrer les modifications apportées à un contact
 */
void MainWindow::saveModification()
{
    QPushButton * clickedButton = (QPushButton *)sender();
    QString idContact =clickedButton->objectName();

    contactIsModified();
    // Sauvegarde de la photo si elle a été changé
    qDebug() <<fichier;
    if(fichier != contactModified.getPhoto())
    {
        QString destination = "../Projet/Files/"+contactModified.getPrenom();
        while(!(QFile::copy(fichier, destination)))
        {
            qDebug()<<"not ok";
            QFile::remove(destination);
        }
        fichier = destination;
    }
    contactModified.setPhoto(fichier);
    qDebug() <<fichier;
    // Modification du contact dans la base de données
    datas.updateContact(gestC.getContactByID(idContact), contactModified);
    // Modification des intéractions dans la base de données
    for(auto interact : listInteractionModified)
        datas.updateInteraction(gestC.getInteraction(interact.getID()), interact);
    // Modification des tâches dans la base de données
    for(auto todo : listTodoModified)
        datas.updateTodo(gestC.getTodo(todo.getID()), todo);
    // Rafraichissement des données
    refresh();
    // retour page tous les contacts
    seeAllContacts();
}

/**
 * @brief MainWindow::selected
 * @param state
 */
void MainWindow::selected(int state)
{
    QCheckBox * checked = (QCheckBox *)sender();
    QString thechecked = checked->text();

    if(state == Qt::Unchecked)
    {
        if(thechecked == "Nom")
            selection -= 1;
        else if(thechecked == "Prenom")
            selection -= 2;
        else
            selection -= 4;
    }
    else
    {
        if(thechecked == "Nom")
            selection += 1;
        else if(thechecked == "Prenom")
            selection += 2;
        else
            selection += 4;
    }
    qDebug()<<"Selection : " << selection;
}

/**
 * @brief MainWindow::selectedCombo
 * @param index
 */
void MainWindow::selectedCombo(int index)
{
    if(index != 0)
    {
        cb_nom->setDisabled(true);
        cb_prenom->setDisabled(true);
        cb_entreprise->setDisabled(true);
        if(index == 1)
            boom->setObjectName("1");
        else
            boom->setObjectName("2");
    }
    else
    {
        cb_nom->setEnabled(true);
        cb_prenom->setEnabled(true);
        cb_entreprise->setEnabled(true);
        boom->setObjectName("0");
    }
}

/**
 * @brief MainWindow::searching
 */
void MainWindow::searching()
{
    QPushButton* clickedButton = (QPushButton*)sender();
    QString choix = clickedButton->objectName();
    if(choix == "0") searchingContact();
    else if(choix == "1") searchingInteraction();
    else searchingTodo();
}

/**
 * @brief MainWindow::searchingContact
 */
void MainWindow::searchingContact()
{
    if(search->text() == "")
        selection = -1;

    // Les dates de début et de fin de filtre
    QString date_from = "";
        if(b_from->text() != "Du")
        {
            date_from = b_from->text();
            if(selection == -1) selection = 0;
        }
        else
            date_from = "0000/00/00";

    QString date_to = "";
        if(b_to->text() != "Au")
        {
            date_to = b_to->text();
            if(selection == -1) selection = 0;
        }
        else
            date_to = QDate::currentDate().toString("yyyy/MM/dd");

    switch (selection)
    {
    case 0:
        emit searchContactByAllInfo(searchResult, search->text(), date_from, date_to);
    break;
    case 1:
        emit searchContactByNom(searchResult, search->text(), date_from, date_to);
    break;
    case 2:
        emit searchContactByPrenom(searchResult, search->text(), date_from, date_to);
    break;
    case 3:
        emit searchContactByNomPrenom(searchResult, search->text(), date_from, date_to);
    break;
    case 4:
        emit searchContactByEntreprise(searchResult, search->text(), date_from, date_to);
    break;
    case 5:
        emit searchContactByNomEntreprise(searchResult, search->text(), date_from, date_to);
    break;
    case 6:
        emit searchContactByPrenomEntreprise(searchResult, search->text(), date_from, date_to);
    break;
    case 7:
        emit searchContactByNomPrenomEntreprise(searchResult, search->text(), date_from, date_to);
    break;
    default:
        searchResult.clear();
        searchResult = gestC.getListContact();
    }
    sender()->setObjectName("0");
    createAllContactPageWidget();
    if(searchResult.size() != 0)
        exportJason();
}

/**
 * @brief MainWindow::searchingInteraction
 */
void MainWindow::searchingInteraction()
{
    QString date_from = "";
        if(b_from->text() != "Du")
            date_from = b_from->text();
        else
            date_from = "0000/00/00";

    QString date_to = "";
        if(b_to->text() != "Au")
            date_to = b_to->text();
        else
            date_to = QDate::currentDate().toString("yyyy/MM/dd");

    emit searchContactInteraction(searchResult, listInteractionModified, search->text(), date_from, date_to);

    auto interact = listInteractionModified.begin();
    auto contact = searchResult.begin();
    while(interact != listInteractionModified.end() || contact != searchResult.end())
    {
        interact->setContact(gestC.getContactAdr(contact->getID()));
        interact++;
        contact++;
    }

    searchResult.clear();

    sender()->setObjectName("1");
    createAllContactPageWidget();
}

/**
 * @brief MainWindow::searchingTodo
 */
void MainWindow::searchingTodo()
{
    QString date_from = "";
        if(b_from->text() != "Du")
            date_from = b_from->text();
        else
            date_from = "0000/00/00";

    QString date_to = "";
        if(b_to->text() != "Au")
            date_to = b_to->text();
        else
            date_to = "9999/12/31";

    emit searchContactTodo(listInteractionModified, listTodoModified, search->text(), date_from, date_to);

    auto interact = listInteractionModified.begin();
    auto todo = listTodoModified.begin();
    while(interact != listInteractionModified.end() || todo != listTodoModified.end())
    {
        todo->setInteraction(gestC.getGestInteraction()->getInteractionAdr(interact->getID()));
        interact++;
        todo++;
    }

    listInteractionModified.clear();

    sender()->setObjectName("2");
    createAllContactPageWidget();
}

/**
 * @brief MainWindow::exportJason Exportation des resultats d'une recherche de contact en fichier Json
 */
void MainWindow::exportJason()
{
    int ret = QMessageBox::information(0, "Export en Json","Voulez-vous exporter les resultats de la recherche en fichier Json ?", QMessageBox::Cancel|QMessageBox::Ok, QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
    {
       QJsonObject obj;
       for(auto contact:searchResult)
       {
           obj.insert("Nom", contact.getNom());
           obj.insert("Prenom", contact.getPrenom());
           obj.insert("Entreprise", contact.getEntreprise());
           obj.insert("Telephone", contact.getTelephone());
           obj.insert("Mail", contact.getEmail());
           obj.insert("Urlphoto", contact.getPhoto());
           obj.insert("Date creation", contact.getStringDateCreation());
           obj.insert("Date modification", contact.getStringDateLastModif());

           QJsonDocument doc(obj);
           QByteArray qbArray= doc.toJson();

           QFile file("../Projet/Files/file.json");
           if(!file.open(QIODevice::Append | QIODevice::Text))
               return;
           QTextStream flux(&file);
           flux.setCodec("UTF-8");

           flux<< qbArray<<Qt::endl;
       }

     }
}
