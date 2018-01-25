#ifndef __XML_ITEM_HPP__
#define __XML_ITEM_HPP__

#include <QVector>
#include <QString>

class QXmlItem
{
public:
	QXmlItem(void);
	QXmlItem(QXmlItem *parent);
	~QXmlItem(void);

	void SetParent(QXmlItem *parent);
	QXmlItem *Parent(void);
	bool HasParent(void);

	void AddEnfant(QXmlItem *enfant);
	QXmlItem *Enfant(const int nIndiceEnfant);
	int NombreEnfant(void);

	void SetValeur(const QString sValeur);
	QString Valeur(void);

	void SetTag(const QString sTag);
	QString Tag(void);

	void AddAttribut(const QString sAttribut);
	QString Attribut(const int nIndiceAttribut);
	int NombreAttribut(void);

	QVector<QXmlItem *> RechercherTag(QXmlItem *racine, const QString sTag);
	QVector<QXmlItem *> RechercherValeur(QXmlItem *racine, const QString sValeur);

	int NombreTotalElements(void);

private:
	QVector<QXmlItem *>			*_pvEnfant;
	QVector<QString>			*_pvAttribut;
	QString						_sTag;
	QString						_sValeur;
	QXmlItem					*_pParent;

	void RechercherValeur(QXmlItem *racine, const QString sValeur, QVector<QXmlItem *> *pvItem);
	void RechercherTag(QXmlItem *racine, const QString sTag, QVector<QXmlItem *> *pvItem);
	void Init(void);
	int ParcourirEtCompter(QXmlItem *element, int nCompteur);
protected:
};

#endif
