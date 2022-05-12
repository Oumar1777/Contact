#include "database.h"

#include <QSqlRecord>
#include <QFile>
#include <QDir>

DataBase::DataBase()
{
    connexion();
}

DataBase::~DataBase()
{
    if(isOpen())
        database.close();
}

void DataBase::connexion()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/home/bah/Bureau/L3/S5/Projets-S5/CDAA/Projet Partie Graphique/Projet/Files/base.sqlite");

    qDebug()<< QDir::currentPath();

    if(QFile::exists("../Files/base.sqlite"))
        qDebug() << "Le fichier existe !!";
    else
        qDebug() << "Pas trouvé";

    if(database.open()){
        qDebug() << "Open ok ";
    // Ouverture avec succès de la base de données
        open = true;
    }
    else{
        qDebug() << "Open not ok ";
        // Erreur lors de l'ouverture de la base de données
        open = false;
        // Envoie un signal d'erreur;
        emit errorDataBase("Erreur!! Problème rencontré lors de l'ouverture de la base de données");
    }
}

/**
 * @brief DataBase::refreshingContacts Cette fonction permet de mettre à jour la liste des contacts
 * @param gest: le gestionnaire de contact à mettre à jour
 */
void DataBase::refreshingContacts(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM CONTACT");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des contacts");
        else
        {
            gest.getListContactAdr()->clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                gest.addContact(contact);
            }
        }
    }
}

/**
 * @brief DataBase::refreshingInteractions Cette fonction permet de charger toutes les intéractions dans la base de données
 * @param gest : le gestionnaire de contact dans lequel se trouve également toutes les intéractions
 */
void DataBase::refreshingInteractions(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM INTERACTION");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des interactions");
        else
        {
            gest.getGestInteraction()->getListInteractionAdr()->clear();
            Interaction interact;
            QString idcontact;
            while(query.next())
            {
                interact.setID(query.value(0).toString());
                interact.setContenu(query.value(1).toString());
                interact.setDate(QDate::fromString(query.value(2).toString(), "yyyy/MM/dd"));
                idcontact = query.value(3).toString();
                gest.addContactInteraction(idcontact, interact);
            }
        }
    }
}

/**
 * @brief DataBase::refreshTodos Cette fonction permet de charger toutes les tâches dans la base de données
 * @param gest : le gestionnaire de contact dans lequel se trouve également toutes les tâches
 */
void DataBase::refreshingTodos(GestionContact& gest)
{
    if(isOpen())
    {
        QSqlQuery query("SELECT * FROM TODO");
        if(!query.exec())
            emit errorDataBase("ERREUR !! Rafraichissement liste des tâches");
        else
        {
            gest.getGestTodo()->getlistTodoAdr()->clear();
            Todo todo;
            QString idinteract;
            while(query.next())
            {
                todo.setID(query.value(0).toString());
                todo.setContenu(query.value(1).toString());
                todo.setDate(QDate::fromString(query.value(2).toString(),"yyyy/MM/dd"));
                idinteract = query.value(3).toString();
                gest.addInteractionTodo(idinteract, todo);
            }
        }
    }
}

/**
 * @brief DataBase::refresh Pour rafraichir toutes les listes : contact, intéraction, todo dans le gestionnaire
 * @param gest le gestionnaire à rafraîchir
 */
void DataBase::refreshing(GestionContact& gest)
{
    refreshingContacts(gest);
    refreshingInteractions(gest);
    refreshingTodos(gest);
    emit refreshed();
}

/**
 * @brief DataBase::addContact Ajouter un contact à la base de données
 * @param contact : le contact à ajouter dans la base
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addContact(const Contact & contact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO CONTACT(nom, prenom, entreprise, telephone, uriphoto, datecreation, datelastmodif, mail) VALUES (:name, :lastname, :ent, :tel, :url, :dtc, :dtl, :m)");
        query.bindValue(":name", contact.getNom());
        query.bindValue(":lastname", contact.getPrenom());
        query.bindValue(":ent", contact.getEntreprise());
        query.bindValue(":tel", contact.getTelephone());
        query.bindValue(":url", contact.getPhoto());
        query.bindValue(":dtc", contact.getDateCreation().toString("yyyy/MM/dd"));
        query.bindValue(":dtl", contact.getDateLastModif().toString("yyyy/MM/dd"));
        query.bindValue(":m", contact.getEmail());
        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact "+contact.getNom()+"  "+contact.getPrenom()+"n'a pas été inséré");
        else
        {
            emit infoDataBase("Nouveau contact inséré : "+contact.getNom()+" "+contact.getPrenom());
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeConctact Supprimer un contact de la base de données
 * @param idContact : l'identifiant du contact à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeConctact(const QString& idContact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM CONTACT WHERE idcontact = :id");
        query.bindValue(":id",idContact);
        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact n'a pas été supprimé");
        else
        {
            emit infoDataBase("Contact Supprimé");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::getContact Ce fonction permet de recupérer un contact en connaissant son nom, son prenom et son entreprise
 * @param nom : le nom du contact à recupérer
 * @param prenom : son prenom
 * @param entreprise : son entreprise
 * @return le contact
 * @warning Si le contact est absent de la base on retourne un contact avec un id à NULL
 */
Contact DataBase::getContact(const QString& nom, const QString& prenom, const QString& entreprise)
{
    Contact contact; contact.setID("NULL");
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE nom = :n AND prenom = :p AND entreprise = :e");
        query.bindValue(":n", nom);
        query.bindValue(":p", prenom);
        query.bindValue(":e", entreprise);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact");
        else
        {
            contact.setID(query.value(0).toString());
            contact.setNom(query.value(1).toString());
            contact.setPrenom(query.value(2).toString());
            contact.setEntreprise(query.value(3).toString());
            contact.setTelephone(query.value(4).toString());
            contact.setPhoto(query.value(5).toString());
            contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
            contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
            contact.setEmail(query.value(8).toString());
        }
    }
    return contact;
}

/**
 * @brief DataBase::updateContact Modifier les informations sur un contact
 * @param oldContact : il contient les anciennes informations sur le contact
 * @param newContact : il contient les nouvelles informations sur le contact
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateContact(const Contact& oldContact, const Contact& newContact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE CONTACT SET nom = :newNom, prenom = :newPrenom, entreprise = :newEnt, telephone = :newTel, uriphoto = :newPhoto, datecreation = :newDC, datelastmodif = :newDL, mail = :newMail WHERE idcontact = :oldID");
        query.bindValue(":newNom", newContact.getNom());
        query.bindValue(":newPrenom", newContact.getPrenom());
        query.bindValue(":newEnt", newContact.getEntreprise());
        query.bindValue(":newTel", newContact.getTelephone());
        query.bindValue(":newPhoto", newContact.getPhoto());
        query.bindValue(":newDC", newContact.getDateCreation().toString("yyyy/MM/dd"));
        query.bindValue(":newDL", newContact.getDateLastModif().toString("yyyy/MM/dd"));
        query.bindValue(":newMail", newContact.getEmail());
        query.bindValue(":oldID", oldContact.getID());

        if(!query.exec())
            emit errorDataBase("ERREUR !! Le contact n'a pas été mis à jour");
        else
        {
            emit infoDataBase("Contact mis à jour");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::addInteraction Ajouter une intéraction dans la base de données;
 * @param interact : l'intéraction à ajouter dans la base
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addInteraction(const Interaction & interact)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO INTERACTION (contenu, date, idcontact) VALUES (:c, :d, :id)");
        query.bindValue(":c", interact.getContenu());
        query.bindValue(":d", interact.getDate().toString("yyyy/MM/dd"));
        query.bindValue(":id", interact.getContact()->getID());


        if(!query.exec())
            emit errorDataBase("ERREUR !! Impossible d'ajouter une nouvelle intéraction dans la base de données");
        else
        {
            emit infoDataBase("Nouvelle interaction ajouté");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeInteraction Supprimer une intéraction de la base de données
 * @param idinteract : l'identifiant de l'intéraction à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeInteraction(const QString& idinteract)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM INTERACTION WHERE idinter = :id");
        query.bindValue(":id",idinteract);
        if(!query.exec())
            emit errorDataBase("ERREUR !! L'interaction n'a pas été supprimé");
        else
        {
            emit infoDataBase("Interaction Supprimé");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::updateInteraction Modifier les informations d'une intéraction
 * @param oldInter : il contient les anciennes informations de l'intéraction
 * @param newInter : il contient les nouvelles informations de l'intéraction
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateInteraction(const Interaction& oldInter, const Interaction& newInter)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE INTERACTION SET contenu = :c, date = :d WHERE idinter = :id");
        query.bindValue(":c", newInter.getContenu());
        query.bindValue(":d", newInter.getDate().toString("yyyy/MM/dd"));
        query.bindValue(":id", oldInter.getID());
        if(!query.exec())
            emit errorDataBase("ERREUR !! L'interaction n'a pas été modifiée");
        else
        {
            emit infoDataBase("Interaction modifiée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::addTodo ajouter une tâche dans la base de données
 * @param td : la tâche à ajouter
 * @return true si l'insertion a été faite, false sinon;
 * @warning un message informera de l'ajout dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::addTodo(const Todo & td)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO TODO (contenu, date, idinter) VALUES (:c, :d, :id)");
        query.bindValue(":c", td.getContenu());
        query.bindValue(":d", td.getDate().toString("yyyy/MM/dd"));
        query.bindValue(":id", td.getInteraction()->getID());

        if(!query.exec())
            emit errorDataBase("ERREUR !! Impossible d'ajouter une nouvelle tâche dans la base de données");
        else
        {
            emit infoDataBase("Nouvelle tâche ajoutée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::removeTodo Supprimer une tâche de la base de données
 * @param idtodo : l'identifiant de la tâche à supprimer
 * @return true si la suppression est une réussite, false sinon
 * @warning un message informera de la suppression de la base de données ou de l'échec de l'opération.
 */
bool DataBase::removeTodo(const QString & idtodo)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM TODO WHERE idTodo = :id");
        query.bindValue(":id",idtodo);
        if(!query.exec())
            emit errorDataBase("ERREUR !! La tâche n'a pas été supprimée");
        else
        {
            emit infoDataBase("Tâche Supprimée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::updateTodo Modifier les informations sur une tâche
 * @param oldTodo : il contient les anciennes informations sur la tâche
 * @param newTodo : il contient les nouvelles informations sur la tâche
 * @return true si la modification se passe sans problème, false sinon
 * @warning un message informera de la mise à jour des informations dans la base de données ou de l'échec de l'opération.
 */
bool DataBase::updateTodo(const Todo & oldTodo, const Todo & newTodo)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE TODO SET contenu = :c, date = :d WHERE idTodo = :id");
        query.bindValue(":c", newTodo.getContenu());
        query.bindValue(":d", newTodo.getDate().toString("yyyy/MM/dd"));
        query.bindValue(":id", oldTodo.getID());
        if(!query.exec())
            emit errorDataBase("ERREUR !! La tâche n'a pas été modifiée");
        else
        {
            emit infoDataBase("Tâche modifiée");
            return true;
        }
    }
    return false;
}

/**
 * @brief DataBase::searchingContactbyNom Recherche des contacts par le nom
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactbyNom(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE nom LIKE :n AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le nom");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByPrenom
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByPrenom(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE prenom LIKE :n AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le prenom");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByEntreprise
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByEntreprise(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE entreprise LIKE :n AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par l'entreprise");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByNomPrenom
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByNomPrenom(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE (nom LIKE :n OR prenom LIKE :n) AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le nom ou le prenom");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByNomEntreprise
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByNomEntreprise(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE (nom LIKE :n OR entreprise LIKE :n) AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le nom ou l'entreprise");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByPrenomEntreprise
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByPrenomEntreprise(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE (entreprise LIKE :n OR prenom LIKE :n) AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le prenom ou l'entreprise");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByNomPrenomEntreprise
 * @param listContact
 * @param keyword
 */
void DataBase::searchingContactByNomPrenomEntreprise(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE (nom LIKE :n OR prenom LIKE :n OR entreprise LIKE :n) AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n", "%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact par le nom, le prénom ou l'entreprise");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactByAllInfo
 * @param listContact
 * @param keyword
 * @param date_from
 * @param date_to
 */
void DataBase::searchingContactByAllInfo(std::list<Contact>& listContact, const QString& keyword, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT WHERE (nom LIKE :n OR prenom LIKE :n OR entreprise LIKE :n OR mail LIKE :n OR telephone LIKE :n) AND datecreation BETWEEN :f AND :t ORDER BY datecreation");
        query.bindValue(":n","%"+keyword+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);


        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche contact");
        else
        {
            listContact.clear();
            Contact contact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                contact.setNom(query.value(1).toString());
                contact.setPrenom(query.value(2).toString());
                contact.setEntreprise(query.value(3).toString());
                contact.setTelephone(query.value(4).toString());
                contact.setPhoto(query.value(5).toString());
                contact.setDateCreation(QDate::fromString(query.value(6).toString(), "yyyy/MM/dd"));
                contact.setDateLastModif(QDate::fromString(query.value(7).toString(), "yyyy/MM/dd"));
                contact.setEmail(query.value(8).toString());
                listContact.push_back(contact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactInteraction
 * @param listInteract
 * @param contact
 * @param date_from
 * @param date_to
 */
void DataBase::searchingContactInteraction(std::list<Contact>& listContact, std::list<Interaction>& listInteract, const QString& contact, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT, INTERACTION WHERE CONTACT.idcontact = INTERACTION.idcontact AND (nom LIKE :n OR prenom LIKE :n OR entreprise LIKE :n OR contenu LIKE :n) AND INTERACTION.date BETWEEN :f AND :t ORDER BY CONTACT.idcontact, date;");
        query.bindValue(":n", "%"+contact+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche intéraction");
        else
        {
            listContact.clear();
            listInteract.clear();
            Contact contact;
            Interaction interact;
            while(query.next())
            {
                contact.setID(query.value(0).toString());
                listContact.push_back(contact);
                interact.setID(query.value(9).toString());
                interact.setContenu(query.value(10).toString());
                interact.setDate(QDate::fromString(query.value(11).toString(), "yyyy/MM/dd"));
                listInteract.push_back(interact);
            }
        }
    }
}

/**
 * @brief DataBase::searchingContactTodo
 * @param listTodo
 * @param contact
 * @param date_from
 * @param date_to
 */
void DataBase::searchingContactTodo(std::list<Interaction>& listInteract, std::list<Todo>& listTodo, const QString& contact, const QString& date_from, const QString& date_to)
{
    if(isOpen())
    {
        QSqlQuery query;
        query.prepare("SELECT * FROM CONTACT, INTERACTION, TODO WHERE CONTACT.idcontact = INTERACTION.idcontact AND INTERACTION.idinter = TODO.idinter AND (nom LIKE :n OR prenom LIKE :n OR entreprise LIKE :n OR TODO.contenu LIKE :n) AND TODO.date BETWEEN :f AND :t ORDER BY CONTACT.idcontact, TODO.date");
        query.bindValue(":n", "%"+contact+"%");
        query.bindValue(":f", date_from);
        query.bindValue(":t", date_to);

        if(!query.exec())
            emit errorDataBase("ERREUR !! Recherche todo");
        else
        {
            listInteract.clear();
            listTodo.clear();
            Interaction interact;
            Todo todo;
            while(query.next())
            {
                todo.setID(query.value(13).toString());
                todo.setContenu(query.value(14).toString());
                todo.setDate(QDate::fromString(query.value(15).toString(), "yyyy/MM/dd"));
                listTodo.push_back(todo);
                interact.setID(query.value(16).toString());
                listInteract.push_back(interact);
            }
        }
    }
}
