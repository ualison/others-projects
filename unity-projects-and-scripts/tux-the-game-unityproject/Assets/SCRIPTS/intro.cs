using UnityEngine;
using System.Collections;

//TEMPO DA TELA DE INICIO

public class intro : MonoBehaviour {
	float tempo = 5;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		tempo -= Time.deltaTime;

		if (tempo <= 0) {
			Application.LoadLevel (1);
			tempo = 5;
		}
	}
}
