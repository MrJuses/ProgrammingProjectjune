#include "stm32f30x_conf.h" // STM32 config
#include "30010_io.h" 		// Input/output library for this course
#include "stdio.h"
#include "stdint.h"
#include "ansi.h"
#include <time.h>
#include <stdlib.h>
#include <sin.h>
#include "charset.h"
#include "visuals.h"
#include "Movement.h"
#include "shoot.h"
#include "lcd.h"
#include "Initialization.h"

//activate boss key
void bossKey(){
	//check for input
	uint8_t variabel;
	variabel = readJoystick();
	clearScreenResCurser();
	//color = green
	fgcolor(10);
	while(1){
		printf("import java.nio.ByteBuffer;"
				"import java.util.List;"
				"import java.util.HashMap;"
				"import java.util.Iterator;"
				"import org.hypertable.thriftgen.*;"
				"public class BasicClientTest {"
				"	public static void main(String [] args) {"
				"		ThriftClient client = null;"
				"		long ns = -1;"
				"		try {"
				"			client = ThriftClient.create('localhost', 38080);"
				"			ns = client.namespace_open('test');"
				"			// HQL examples"
				"			show(client.hql_query(ns, 'show tables').toString());"
				"			show(client.hql_query(ns, 'select * from thrift_test').toString());"
				"			// Schema example"
				"			Schema schema = new Schema();"
				"			schema = client.table_get_schema(ns, 'thrift_test');"
				"			Iterator ag_it = schema.access_groups.keySet().iterator();"
				"			show('Access groups:');"
				"			while (ag_it.hasNext()) {"
				"     			show('\t' + ag_it.next());"
				"			}"
				"			Iterator cf_it = schema.column_families.keySet().iterator();"
				"			show('Column families:');"
				"			while (cf_it.hasNext()) {"
				"				show('\t' + cf_it.next());"
				"			}"
				"			// mutator examples"
				"			long mutator = client.mutator_open(ns, 'thrift_test', 0, 0);"
				"			try {"
				"				Cell cell = new Cell();"
				"				Key key = new Key();"
				"				key.setRow('java-k1');"
				"				key.setColumn_family('col');"
				"				cell.setKey(key);"
				"				String vtmp = 'java-v1';"
				"				cell.setValue( ByteBuffer.wrap(vtmp.getBytes()) );"
				"				client.mutator_set_cell(mutator, cell);"
				"			}"
				"			finally {"
				"				client.mutator_close(mutator);"
				"			}"
				"			// shared mutator example"
				"			MutateSpec mutate_spec = new MutateSpec();"
				"			mutate_spec.setAppname('test-java');mutate_spec.setFlush_interval(1000);"
				"			Cell cell = new Cell();"
				"			Key key;"
				"			key = new Key();"
				"			key.setRow('java-put1');"
				"			key.setColumn_family('col');"
				"			cell.setKey(key);"
				"			String vtmp = 'java-put-v1';"
				"			cell.setValue( ByteBuffer.wrap(vtmp.getBytes()) );"
				"			client.offer_cell(ns, 'thrift_test', mutate_spec, cell);"
				"			key = new Key();"
				"			key.setRow('java-put2');"
				"			key.setColumn_family('col');"
				"			cell.setKey(key);"
				"			vtmp = 'java-put-v2';"
				"			cell.setValue( ByteBuffer.wrap(vtmp.getBytes()) );"
				"			client.shared_mutator_refresh(ns, 'thrift_test', mutate_spec);"
				"			client.shared_mutator_set_cell(ns, 'thrift_test', mutate_spec, cell);"
				"			Thread.sleep(2000);"
				"		}"
				"		catch (Exception e) {"
				"			e.printStackTrace();"
				"			try {"
				"				if (client != null && ns != -1)"
				"				client.namespace_close(ns);"
				"			}"
				"			catch (Exception ce) {"
				"				System.err.println('Problen closing namespace \'test\' - ' + e.getMessage());"
				"			}"
				"			System.exit(1);"
				"		}"
				"	}"
				"	private static void show(String line) {"
				"		System.out.println(line);"
				"	}"
				"}"
				"\n>insert code here<\n");
		//the longer you hold the button the more code will print
		for(int i = 0; i < 100000; i++);
		if (variabel != readJoystick()){
			variabel = readJoystick();
			moveMenu(variabel,210);
			break;
		}
	}
}
