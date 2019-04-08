using UnityEngine;
using System.Collections;

//SCRIPTS DO WINDOWS DO MAL E APPLE DO MAL

public class inimigos : MonoBehaviour {

	void OnCollisionEnter2D(Collision2D col){
		
		if(col.gameObject.tag == "Player"){

				Application.LoadLevel(2);
			
		}
}
}
