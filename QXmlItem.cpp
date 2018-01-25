#include "QXmlItem.hpp"

QXmlItem::QXmlItem(void)
{
	Init();
}

QXmlItem::QXmlItem(QXmlItem *parent)
{
	Init();
	SetParent(parent);
}

QXmlItem::~QXmlItem(void)
{
	if(_pvEnfant)
	{
		_pvEnfant->clear();
		delete _pvEnfant;
		_pvEnfant = NULL; // Optionnel
	}

	if(_pvAttribut)
	{
		_pvAttribut->clear();
		delete _pvAttribut;
		_pvAttribut = NULL; // Optionnel
	}
}

void QXmlItem::Init(void)
{
	_pvEnfant = NULL;
	_pvAttribut = NULL;
	_pParent = NULL;
	_sTag = "";
	_sValeur = "";
}

void QXmlItem::SetParent(QXmlItem *parent)
{
	parent->AddEnfant(this);
	_pParent = parent;
}

QXmlItem * QXmlItem::Parent(void)
{
	return _pParent;
}

bool QXmlItem::HasParent(void)
{
	return _pParent ? true : false;
}

void QXmlItem::AddEnfant(QXmlItem *enfant)
{
	// Si le vecteur n'est pas créé, on le créer
	if(!_pvEnfant)
	{
		_pvEnfant = new QVector<QXmlItem *>;
	}

	_pvEnfant->push_back(enfant);
}

QXmlItem * QXmlItem::Enfant(const int nIndiceEnfant)
{
	if(nIndiceEnfant < 0 || nIndiceEnfant > NombreEnfant())
		return NULL;
	else
		return _pvEnfant->at(nIndiceEnfant);
}

int QXmlItem::NombreEnfant(void)
{
	if(!_pvEnfant)
		return 0;
	else
		return _pvEnfant->size();
}

void QXmlItem::SetValeur(const QString sValeur)
{
	_sValeur = sValeur;
}

QString QXmlItem::Valeur(void)
{
	return _sValeur;
}

void QXmlItem::SetTag(const QString sTag)
{
	_sTag = sTag;
}

QString QXmlItem::Tag(void)
{
	return _sTag;
}

void QXmlItem::AddAttribut(QString sAttribut)
{
	// Si le vecteur n'est pas créé, on le créer
	if(!_pvAttribut)
		_pvAttribut = new QVector<QString>;

	_pvAttribut->push_back(sAttribut);
}

QString QXmlItem::Attribut(const int nIndiceAttribut)
{
	if(nIndiceAttribut < 0 || nIndiceAttribut > NombreAttribut())
		return cErreurAttribut;
	else
		return _pvAttribut->at(nIndiceAttribut);
}

int QXmlItem::NombreAttribut(void)
{
	if(!_pvAttribut)
		return 0;
	else
		return _pvAttribut->size();
}

QVector<QXmlItem *> QXmlItem::RechercherTag(QXmlItem *racine, const QString sTag)
{
QVector<QXmlItem *> vItem;

	RechercherTag(racine, sTag, &vItem);
	return vItem;
}

void QXmlItem::RechercherTag(QXmlItem *racine, const QString sTag, QVector<QXmlItem *> *pvItem)
{
int nIndiceBoucle;

	if(racine->Tag() == sTag)
		pvItem->push_back(racine);

	for(nIndiceBoucle = 0; nIndiceBoucle < racine->NombreEnfant(); nIndiceBoucle++)
	{
		RechercherTag(racine->Enfant(nIndiceBoucle), sTag, pvItem);
	}
}


QVector<QXmlItem *> QXmlItem::RechercherValeur(QXmlItem *racine, const QString sValeur)
{
QVector<QXmlItem *> vItem;

	RechercherValeur(racine, sValeur, &vItem);
	return vItem;
}

void QXmlItem::RechercherValeur(QXmlItem *racine, const QString sValeur, QVector<QXmlItem *> *pvItem)
{
int nIndiceBoucle;

	if(racine->Valeur() == sValeur)
		pvItem->push_back(racine);

	for(nIndiceBoucle = 0; nIndiceBoucle < racine->NombreEnfant(); nIndiceBoucle++)
	{
		RechercherValeur(racine->Enfant(nIndiceBoucle), sValeur, pvItem);
	}
}

int QXmlItem::NombreTotalElements(void)
{
int nCompteur = 0;
	nCompteur = ParcourirEtCompter(this, nCompteur);
	return nCompteur;
}

int QXmlItem::ParcourirEtCompter(QXmlItem *element, int nCompteur)
{
int nIndice;

	for(nIndice = 0; nIndice < element->NombreEnfant(); nIndice++)
	{
		nCompteur++;
		nCompteur = ParcourirEtCompter(element->Enfant(nIndice), nCompteur);
	}
}
