#include "QXmlItem.hpp"

#include <QString>
#include <QDebug>

#define cNombreParent 20
#define cNombreEnfant 1

void AfficherArbre(QXmlItem *pArbre);

int main(void)
{
int nIndiceCreation;
	QXmlItem *arbre = new QXmlItem();
	arbre->SetTag("Racine");
	
	for(int i = 0, nIndiceCreation = 0; i < cNombreParent; i++)
	{
		QXmlItem *enfant = new QXmlItem(arbre);
		enfant->SetTag("Enfant");

		for(int j = 0; j < cNombreEnfant; j++, nIndiceCreation++)
		{
			QXmlItem *ss = new QXmlItem(enfant);
			ss->SetTag("Sous-Enfant");
			ss->SetValeur("SousEnfant");
		}
	}
	
	AfficherArbre(arbre);

	return 0;
}

// Affiche le tag et la valeur du noeud pArbre et parcours les enfants de ce noeud
void AfficherArbre(QXmlItem *pArbre)
{
	qDebug() << "Tag : " << pArbre->Tag() << "		Valeur : " << pArbre->Valeur();

	for(int nIndiceItem = 0; nIndiceItem < pArbre->NombreEnfant(); nIndiceItem++)
	{
		AfficherArbre(pArbre->Enfant(nIndiceItem));
	}
}
