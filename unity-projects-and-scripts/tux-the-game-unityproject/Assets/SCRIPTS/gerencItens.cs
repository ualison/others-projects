using UnityEngine;
using System.Collections;

//Copyright 2015 Ualison Rodrigues

/*Este arquivo é parte do programa TUX: THE GAME

TUX: THE GAME é um software livre; você pode redistribuí-lo e/ou 
modificá-lo dentro dos termos da Licença Pública Geral GNU como 
publicada pela Fundação do Software Livre (FSF); na versão 3 da 
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil, 
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http://www.gnu.org/licenses/>.
*/

//SCRIPT QUE GERENCIA OS ITENS NA TELA

public class gerencItens : MonoBehaviour {
	public Texture2D botao1;
	public Texture2D botao2;
	static public int Dinheiro;
	static public int NumVersoes;
	static public int VerPagas;
	public int tam;
	public Font fonte;
	// Use this for initialization
	void Start () {
		Dinheiro = 0;
		NumVersoes = 0;
		VerPagas = 0;
	}

	void OnGUI(){
		GUI.color = Color.black;
		GUI.skin.label.font = fonte;
		GUI.skin.label.fontSize = tam;
		GUI.Label (new Rect (50, 40, 350, 150), "OBJETIVO: COLETE 5 DISTROS LINUX" + "\n" + "DINHEIRO: " + Dinheiro + "\n" + "VERSÕES COLETADAS: " + NumVersoes + "\n" + "VERSÕES PAGAS COLETADAS: " + VerPagas);
		GUI.backgroundColor = Color.clear;
		if (GUI.Button (new Rect (550, 30, 100, 30), botao1)) {
			Application.LoadLevel(1);
			
		}
		if (GUI.Button (new Rect (550, 80, 100, 30), botao2)) {
			Application.Quit();
		}
	}
}
