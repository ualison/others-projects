using UnityEngine;
using System.Collections;

//SCRIPT COLETOR DO WINDOWS PAGO

public class coletores2 : MonoBehaviour {
	public AudioClip somCol;
	
	void OnCollisionEnter2D(Collision2D col){
		
		if(col.gameObject.tag == "Player"){
			if(gerencItens.Dinheiro >= 1500){
			Destroy(gameObject);
			AudioSource.PlayClipAtPoint(somCol, new Vector2(transform.position.x, transform.position.y));
			gerencItens.VerPagas +=1;
			}
			
		}
	}
}