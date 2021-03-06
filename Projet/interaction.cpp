/**
    *@file Interaction.cpp
    *@brief Fichier CPP de la classe Interaction
    *@author BAH Saikou Oumar
    *@author Diallo Mamoudou
*/

#include "interaction.h"

/**
    *@brief Constructeur par défaut.
    *@details Ce constructeur initialise une interaction avec un contenu vide et horodaté avec la date courante.
*/
Interaction::Interaction()
{
    date = QDate::currentDate();
    contenu = "";
    id = "";
}

/**
 * @brief Constructeur avec paramètre contact associé.
 * @param c : pointeur sur le contact associé.
 */
Interaction::Interaction(Contact* c)
{
    contact = c;
    date = QDate::currentDate();
    contenu = "";
    id = "";
}

/**
    *@brief Constructeur avec paramètre
    *@details Ce constructeur initialise une interaction avec un contenu et la date courante.
    *@param c : le contenu de l'interaction
*/
Interaction::Interaction(Contact* c, const QString& cont)
{
    date = QDate::currentDate();
    contenu = cont;
    contact = c;
    id = "";
}

/**
    *@brief Constructeur avec paramètre
    *@details Ce constructeur initialise une interaction avec un contenu et une date donnée.
    *@param c : le contenu de l'interaction
*/
Interaction::Interaction(Contact* c, const QString& cont, const QDate& d)
{
    date = d;
    contenu = cont;
    contact = c;
    id = "";
}

/**
    *@brief Constructeur de recopie
    *@details Ce constructeur initialise une nouvelle interaction en copiant une autre.
    *@param autre : l'interaction à copier
*/

Interaction::Interaction(const Interaction& autre)
{
    date = autre.getDate();
    contenu = autre.getContenu();
    id = autre.getID();
    contact = autre.getContact();
}

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie la date de création de l'intéraction.
    *@return QDate : la date de création de l'intéraction.
*/
QDate Interaction::getDate() const
{
    return date;
}

/**
    *@brief Pour récupérer la date.
    *@details Cette fonction renvoie la date de création de l'intéraction dans une QString.
    *@return QString : la date de création de l'intéraction au format (dd/MM/yyyy).
*/
QString Interaction::getStringDate() const
{
    if(date == QDate::currentDate())
        return "Aujourd'hui";
    else
        return date.toString("dd/MM/yyyy");
}

/**
    *@brief Pour recupérer l'identifiant de l'interaction.
    *@details Cette fonction renvoie l'identifiant de l'interaction.
*/
QString Interaction::getID() const
{
    return this->id;
}

/**
    *@brief Pour recupérer le contenu de l'interaction.
    *@details Cette fonction renvoie la chaine contenu de l'interaction.
*/
QString Interaction::getContenu() const
{
    return this->contenu;
}

/**
    *@brief Pour recupérer l'adresse du contact.
    *@details Cette fonction renvoie l'adresse du contact associé à l'intéraction.
    *@return un pointeur sur Contact.
*/
Contact* Interaction::getContact() const
{
    return contact;
}

/**
    *@brief Pour affecter une date à l'interaction.
    *@param dt : QDate.
*/
void Interaction::setDate(const QDate& dt)
{
   date = dt;
}

/**
    *@brief Pour affecter une date à l'interaction.
    *@param dt : QString au format dd/MM/yyyy.
    *@return vrai si la date est valide, false sinon
    *@warning la date n'est pas modifiée si elle est invalide
*/
bool Interaction::setDateFromString(const QString& dt)
{
   if(QDate::fromString(dt,"dd/MM/yyyy").isValid())
   {
       date = QDate::fromString(dt,"dd/MM/yyyy");
       return true;
   }
   return false;
}

/**
    *@brief Pour affecter un identifiant à l'interaction.
    *@param id : L'identifiant de l'intéraction.
*/
void Interaction::setID(const QString& id)
{
   this -> id = id;
}

/**
    *@brief Pour affecter un contenu à l'interaction.
    *@param c : string à affecter au contenu.
*/
void Interaction::setContenu(const QString& c)
{
    this->contenu= c;
}

/**
    *@brief Pour affecter un contact à l'interaction.
    *@param c : adresse sur contact.
*/
void Interaction::setContact(Contact *c)
{
    contact = c;
}

/**
    *@brief Surcharge de l'opérateur << pour l'affichage.
    *@param os : de type QDebug.
    *@param i: de type Interaction qui represente l'interface à afficher.
    *@details Pour afficher une Interaction, on affiche la date de l'interaction, ou Aujourd'hui s'il s'agit de la date courante, suivie son contenu.
*/
QDebug operator<<(QDebug os, const Interaction& i)
{
    os << "Ct " << i.getContact()->getID() << " : Interaction " << i.getID() << i.getStringDate();
    os << i.getContenu() << "\n";
    return os;
}


/**
    *
*/
QString Interaction::toString() const
{
    QString it = "Interaction "+getID()+" : "+getStringDate() + "\n";
    it += getContenu()+"\n";
    return it;
}

/**
    *@brief Surchage de l'opérateur de comparaison (==)
    *@details On considère que deux intéractions sont identiques si elles ont même contenu.
    *@param autre : l'intéraction à comparer avec l'intéraction courante.
    *@return un booléen : true si elles ont le même contenu, false sinon.
*/
bool Interaction::operator==(const Interaction& autre)
{
    return getID() == autre.getID();
}

/**
    *@brief Surchage de l'opérateur d'affection (=)
    *@details L'intéraction actuelle reçoit le contenu et la date de l'autre intéraction.
    *@param autre : l'intéraction à affecter.
*/
void Interaction::operator=(const Interaction& autre)
{
    id = autre.getID();
    date = autre.getDate();
    contenu = autre.getContenu();
    contact = autre.getContact();
}
