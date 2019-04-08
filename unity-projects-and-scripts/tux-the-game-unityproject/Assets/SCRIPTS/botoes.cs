using UnityEngine;
using System.Collections;

//SCRIPT DOS BOTOES DO MENU

public class botoes : MonoBehaviour {
	public Texture2D botao1;
	public Texture2D botao2;
	public Texture2D botao3;
	public Texture2D credSair;
	public Texture2D fundoCred;
	public bool abriuCred = false;

	void OnGUI(){
		GUI.backgroundColor = Color.clear;
		if (GUI.Button (new Rect (300, 250, 150, 60), botao1)) {
			Application.LoadLevel(2);

		}
		if (GUI.Button (new Rect (300, 300, 150, 60), botao2)) {
			Application.Quit();
		}
		if (GUI.Button (new Rect (640, 70, 100, 40), botao3)) {
			abriuCred = true;

		}
		if (abriuCred == true) {
			GUI.Label (new Rect (200, 150, 400, 400), fundoCred);
			if (GUI.Button (new Rect (640, 120, 70, 30), credSair)) {
				abriuCred = false;
			}
		}
		}
	}

