using UnityEngine;
using System.Collections;

//SCRIPT PC, INDICA QUE PASSOU DE FASE SE PEGAR AS 5 DISTROS LINUX

public class pc : MonoBehaviour {

	
	void OnCollisionEnter2D(Collision2D col){
		
		if(col.gameObject.tag == "Player"){
			if(gerencItens.NumVersoes == 5)
				Application.LoadLevel(1);
			
		}
}
}
