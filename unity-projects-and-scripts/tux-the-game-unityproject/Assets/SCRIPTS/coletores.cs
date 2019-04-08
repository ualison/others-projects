using UnityEngine;
using System.Collections;

//SCRIPT COLETOR DAS DISTROS LINUX

public class coletores : MonoBehaviour {
	public AudioClip somCol;
	
	void OnCollisionEnter2D(Collision2D col){
		
		if(col.gameObject.tag == "Player"){
			Destroy(gameObject);
			AudioSource.PlayClipAtPoint(somCol, new Vector2(transform.position.x, transform.position.y));
			gerencItens.NumVersoes +=1;
			
		}
	}
}